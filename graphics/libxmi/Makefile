# $NetBSD: Makefile,v 1.4 2020/01/18 23:32:15 rillig Exp $

DISTNAME=	libxmi-1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=libxmi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libxmi/
COMMENT=	C/C++ function library for rasterizing 2D vector graphics
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf
GNU_CONFIGURE=		yes
INFO_FILES=		yes

pre-configure:
	cd ${WRKSRC} && autoconf

SUBST_CLASSES+=		aclocal
SUBST_STAGE.aclocal=	pre-configure
SUBST_MESSAGE.aclocal=	Fixing aclocal
SUBST_FILES.aclocal=	aclocal.m4
SUBST_SED.aclocal=	-e 's,--no-verify,,'

.include "../../mk/bsd.pkg.mk"
