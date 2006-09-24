# $NetBSD: Makefile,v 1.24 2006/09/24 16:22:16 joerg Exp $

DISTNAME=	cmake-2.4.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/v2.4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cmake.org/
COMMENT=	Cross platform make

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_NCURSES=		yes
GNU_CONFIGURE=		yes
CONFIGURE_HAS_MANDIR=	no
CONFIGURE_ARGS+=	--mandir=/${PKGMANDIR}
BUILD_TARGET=		default_target

SUBST_CLASSES+=		cmake
SUBST_STAGE.cmake=	pre-configure
SUBST_MESSAGE.cmake=	Fixing hard-coded prefix.
SUBST_FILES.cmake=	Modules/FindCurses.cmake Modules/FindX11.cmake
SUBST_SED.cmake=	-e "s|@prefix@|${PREFIX}|g"
SUBST_SED.cmake=	-e "s|@x11base@|${X11BASE}|g"

post-extract:
	${CP} ${WRKSRC}/Modules/Platform/FreeBSD.cmake \
		${WRKSRC}/Modules/Platform/DragonFly.cmake

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
