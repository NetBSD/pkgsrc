# $NetBSD: Makefile,v 1.22 2019/11/02 21:09:18 rillig Exp $
#

DISTNAME=	wmsmixer-0.5.1
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.hibernaculum.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.hibernaculum.net/wmsmixer/
COMMENT=	Another mixer designed for WindowMaker (dockapp)
LICENSE=	gnu-gpl-v2

NOT_FOR_PLATFORM=	Interix-*-*

USE_IMAKE=		YES
USE_LANGUAGES=		c++
NO_INSTALL_MANPAGES=	YES

MAKE_FLAGS+=	CCOPTIONS=${CFLAGS:Q}
MAKE_FLAGS+=	CXXOPTIONS=${CFLAGS:Q}
MAKE_FLAGS+=	LOCAL_LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS+=	share/doc/wmsmixer share/examples/wmsmixer

pre-build:
	${TOUCH} ${WRKSRC}/wmsmixer.man

post-install:
	${INSTALL_DATA} ${WRKSRC}/home.wmsmixer \
		${DESTDIR}${PREFIX}/share/examples/wmsmixer
	${INSTALL_DATA} ${WRKSRC}/README.wmmixer \
		${DESTDIR}${PREFIX}/share/doc/wmsmixer/README.wmsmixer

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
