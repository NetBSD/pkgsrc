# $NetBSD: Makefile,v 1.97 2024/05/16 06:14:52 wiz Exp $

DISTNAME=	bzflag-2.4.22
PKGREVISION=	17
CATEGORIES=	games
MASTER_SITES=	https://download.bzflag.org/bzflag/source/${PKGVERSION_NOREV}/

MAINTAINER=	blymn@NetBSD.org
HOMEPAGE=	https://www.bzflag.org/
COMMENT=	OpenGL tank game
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
FAKE_NCURSES=	yes	# They assume non ncurses is Solaris
USE_CURSES=	resizeterm

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} !=  "Linux"
SUBST_CLASSES+=		fixme
SUBST_STAGE.fixme=	pre-configure
SUBST_FILES.fixme=	src/platform/Makefile.in
SUBST_SED.fixme=	-e "s|@LINUX_TRUE@||g"
SUBST_SED.fixme+=	-e "s|@LINUX_FALSE@|\#|g"
.endif

CHECK_PORTABILITY_SKIP+=	debian/*

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
