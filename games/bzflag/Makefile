# $NetBSD: Makefile,v 1.11 2004/02/28 06:08:16 xtraeme Exp $

DISTNAME=	bzflag-1.10.20031209
PKGNAME=	${DISTNAME:S/20031209/0/}
CATEGORIES=	games x11
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=bzflag/}

MAINTAINER=	blymn@baea.com.au
HOMEPAGE=	http://www.bzflag.org/
COMMENT=	OpenGL tank game

WRKSRC=		${WRKDIR}/bzflag-1.9.10.20031209
GNU_CONFIGURE=	yes
USE_NCURSES=	# resize_term()
USE_X11=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_PERL5=	build
USE_LANGUAGES=	c c++

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
