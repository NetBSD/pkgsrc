# $NetBSD: Makefile,v 1.19 2005/06/02 14:24:04 blymn Exp $

DISTNAME=	bzflag-2.0.2.20050318
PKGNAME=	${DISTNAME:S/.20050318//}
PKGREVISION=	0
CATEGORIES=	games x11
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=bzflag/}

MAINTAINER=	dtremenak@users.sourceforge.net	
HOMEPAGE=	http://www.bzflag.org/
COMMENT=	OpenGL tank game

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_NCURSES=	# resize_term()
USE_PERL5=	build
USE_X11=	yes
CPPFLAGS+=      -I/usr/pkg/include -I${X11BASE}/include

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} !=  "Linux"
SUBST_CLASSES+=	    fixme
SUBST_STAGE.fixme=  post-patch
SUBST_FILES.fixme=  src/platform/Makefile.in
SUBST_SED.fixme=    -e "s|@LINUX_TRUE@||g"
SUBST_SED.fixme+=   -e "s|@LINUX_FALSE@|\#|g"
.endif

CONFIGURE_ARGS+=	--with-ncurses

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
