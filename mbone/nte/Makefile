# $NetBSD: Makefile,v 1.10 1998/09/15 17:05:05 agc Exp $
#

DISTNAME=	nt.1.5a23
PKGNAME=	nte-1.5a23
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://cs.ucl.ac.uk/mice/nte/

MAINTAINER=	mycroft@netbsd.org

.include "../../mk/bsd.prefs.mk"

.ifdef WRKOBJDIR
BUILD_ROOT=	${WRKOBJDIR}
.else
BUILD_ROOT=	${PKGSRCDIR}
.endif

BUILD_DEPENDS=	${BUILD_ROOT}/x11/tk80/${WRKDIR:T}/tk8.0/generic/default.h:${TK_DIR}:configure
DEPENDS+=	tk-8.0p2:../../x11/tk80

TK_DIR=         ${BUILD_ROOT}/x11/tk80
TK_SRC=		${TK_DIR}/${WRKDIR:T}/tk8.0

RESTRICTED=	"Contains DES encryption"
MIRROR_DISTFILE=no
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
# Pass this on to our child
MAKE_ENV=	TK_SRC=${TK_SRC}

do-configure:
	cd ${WRKSRC}/netbsd && sh configure

.include "../../mk/bsd.pkg.mk"

#DISGUSTING HACK ALERT
#Although nte includes an hsearch.c for those who don't have it in
# libc, there's no way to get the default Makefile to build it.
# So we build it here.
#This is below the .include "../../mk/bsd.pkg.mk" since variable names in
# targets or dependencies are evaluated when they are read so
# bsd.pkg.mk must have defined ${WRKSRC} already.
pre-build:	${WRKSRC}/netbsd/hsearch.o

${WRKSRC}/netbsd/hsearch.o:	${WRKSRC}/src/hsearch.c
		${CC} -I${WRKSRC}/src ${CFLAGS} -c -o $@ ${WRKSRC}/src/hsearch.c
