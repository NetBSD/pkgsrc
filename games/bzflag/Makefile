# $NetBSD: Makefile,v 1.12 2004/03/02 23:14:31 snj Exp $

DISTNAME=	bzflag-1.10.4.20040125
PKGNAME=	${DISTNAME:S/.20040125//}
CATEGORIES=	games x11
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=bzflag/}

MAINTAINER=	blymn@baea.com.au
HOMEPAGE=	http://www.bzflag.org/
COMMENT=	OpenGL tank game

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_NCURSES=	# resize_term()
USE_PERL5=	build
USE_X11=	yes

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
.include "../../graphics/Mesa/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
