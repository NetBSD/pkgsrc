# $NetBSD: Makefile,v 1.3 2000/10/15 12:06:34 rh Exp $
#

DISTNAME=	SDL-1.1.5
CATEGORIES=	devel games
MASTER_SITES=	http://www.libsdl.org/release/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.libsdl.org/

BUILD_DEPENDS+= ${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+= ${LOCALBASE}/bin/automake:../../devel/automake
DEPENDS+=	pth>=1.3.5:../../devel/pth
#DEPENDS+=	unproven-pthreads>=0.16
DEPENDS+=	esound>=0.2.18:../../audio/esound

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_MESA=	YES
USE_X11=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
LDFLAGS+=	-Wl,-R${X11BASE}/lib
#CC=		${LOCALBASE}/pthreads/bin/pgcc

pre-patch:
	cd ${WRKSRC} && ${MKDIR} src/audio/netbsd

post-patch:
	cd ${WRKSRC} && autoconf

post-configure:
	cd ${WRKSRC}/src/audio && ${CP} *.[ch] netbsd/

.include "../../mk/bsd.pkg.mk"
