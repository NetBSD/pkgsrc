# $NetBSD: Makefile,v 1.46 2014/05/29 23:35:37 wiz Exp $

DISTNAME=	nasm-2.11.02
PKGREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	http://www.nasm.us/pub/nasm/releasebuilds/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nasm.us/
COMMENT=	General-purpose x86 assembler
# actually only 2-clause BSD
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

AUTO_MKDIRS=		yes

USE_TOOLS+=		gmake makeinfo perl
GCC_REQD+=		3.0
GNU_CONFIGURE=		yes
#MAKE_JOBS_SAFE=		NO

INFO_FILES=		yes
BUILD_TARGET=		everything
INSTALL_TARGET=		install_everything

INSTALL_ENV+=	INSTALLROOT=${DESTDIR}

MAKE_ENV+=	PERL5=${PERL5:Q}

.include "../../mk/bsd.pkg.mk"
