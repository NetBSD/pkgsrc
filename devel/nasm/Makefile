# $NetBSD: Makefile,v 1.43 2013/05/31 12:40:01 wiz Exp $

DISTNAME=	nasm-2.07
PKGREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nasm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nasm.sourceforge.net/
COMMENT=	General-purpose x86 assembler
# actually only 2-clause BSD
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

AUTO_MKDIRS=		yes

USE_TOOLS+=		gmake makeinfo perl
GCC_REQD+=		3.0
GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		NO

INFO_FILES=		yes
BUILD_TARGET=		everything
INSTALL_TARGET=		install_everything

INSTALL_ENV+=	INSTALLROOT=${DESTDIR}

MAKE_ENV+=	PERL5=${PERL5:Q}

.include "../../mk/bsd.pkg.mk"
