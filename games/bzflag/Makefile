# $NetBSD: Makefile,v 1.52 2016/03/05 11:28:30 jperkin Exp $

DISTNAME=	bzflag-2.4.2
PKGREVISION=	7
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
USE_NCURSES=	# resize_term()

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} !=  "Linux"
SUBST_CLASSES+=	    fixme
SUBST_STAGE.fixme=  post-patch
SUBST_FILES.fixme=  src/platform/Makefile.in
SUBST_SED.fixme=    -e "s|@LINUX_TRUE@||g"
SUBST_SED.fixme+=   -e "s|@LINUX_FALSE@|\#|g"
.endif

CONFIGURE_ARGS+=	--with-ncurses

CHECK_PORTABILITY_SKIP+=	debian/*

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
