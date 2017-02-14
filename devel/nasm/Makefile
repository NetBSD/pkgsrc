# $NetBSD: Makefile,v 1.53 2017/02/14 08:05:30 adam Exp $

DISTNAME=	nasm-2.12.02
CATEGORIES=	devel lang
MASTER_SITES=	http://www.nasm.us/pub/nasm/releasebuilds/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nasm.us/
COMMENT=	General-purpose x86 assembler
# actually only 2-clause BSD
LICENSE=	modified-bsd

AUTO_MKDIRS=		yes

USE_TOOLS+=		gmake makeinfo perl
GCC_REQD+=		3.0
GNU_CONFIGURE=		yes

INFO_FILES=		yes
BUILD_TARGET=		everything
INSTALL_TARGET=		install_everything

INSTALL_ENV+=	INSTALLROOT=${DESTDIR}

MAKE_ENV+=	PERL5=${PERL5:Q}

.include "../../mk/bsd.pkg.mk"
