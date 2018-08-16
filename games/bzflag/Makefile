# $NetBSD: Makefile,v 1.63 2018/08/16 18:54:44 adam Exp $

DISTNAME=	bzflag-2.4.2
PKGREVISION=	16
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bzflag/}

MAINTAINER=	blymn@NetBSD.org
HOMEPAGE=	http://bzflag.org/
COMMENT=	OpenGL tank game
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl
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

CONFIGURE_ARGS+=	--with-ncurses

CHECK_PORTABILITY_SKIP+=	debian/*

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
