# New ports collection makefile for:	nte
# Version required:	1.5a23
# Date created:		5 September 1996
# Whom:	      		mycroft
#
# $NetBSD: Makefile,v 1.2 1998/03/20 07:22:05 mycroft Exp $
#

DISTNAME=	nt.1.5a23
PKGNAME=	nte-1.5a23
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://cs.ucl.ac.uk/mice/nte/

MAINTAINER=	mycroft@NetBSD.ORG

TK_DIR=         ${PORTSDIR}/x11/tk80
TK_SRC=		${TK_DIR}/work/tk8.0

DEPENDS=	${TK_DIR}:configure
LIB_DEPENDS=	tk80:${TK_DIR}

RESTRICTED=	"Contains DES encryption"
MIRROR_DISTFILE=no
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
# Pass this on to our child
MAKE_ENV=	TK_SRC=${TK_SRC}

do-configure:
	cd ${WRKSRC}/netbsd && sh configure

.include <bsd.port.mk>

#DISGUSTING HACK ALERT
#Although nte includes an hsearch.c for those who don't have it in
# libc, there's no way to get the default Makefile to build it.
# So we build it here.
#This is below the .include <bsd.port.mk> since variable names in
# targets or dependencies are evaluated when they are read so
# bsd.port.mk must have defined ${WRKSRC} already.
pre-build:	${WRKSRC}/netbsd/hsearch.o

${WRKSRC}/netbsd/hsearch.o:	${WRKSRC}/src/hsearch.c
		${CC} -I${WRKSRC}/src ${CFLAGS} -c -o $@ ${WRKSRC}/src/hsearch.c
