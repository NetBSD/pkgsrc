# $NetBSD: Makefile,v 1.6 2003/12/13 10:32:53 xtraeme Exp $

DISTNAME=	bzflag-1.10.20031209
WRKSRC=		${WRKDIR}/bzflag-1.9.10.20031209
CATEGORIES=	games x11
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=bzflag/}

MAINTAINER=	blymn@baea.com.au
HOMEPAGE=	http://www.bzflag.org/
COMMENT=	OpenGL tank game

GNU_CONFIGURE=	yes
USE_NCURSES=	# resize_term()
USE_X11=	yes
USE_BUILDLINK2=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} !=  "Linux"
post-extract:
	${SED} -e 's|@LINUX_TRUE@||g ; s|@LINUX_FALSE@|#|g' \
		${WRKSRC}/src/platform/Makefile.in > \
		${WRKSRC}/src/platform/Makefile.sed
	${MV} ${WRKSRC}/src/platform/Makefile.sed \
		${WRKSRC}/src/platform/Makefile.in
.endif

CONFIGURE_ARGS+=	--with-ncurses

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
