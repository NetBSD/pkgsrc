# $NetBSD: Makefile,v 1.4 1998/04/22 14:22:45 agc Exp $
#

DISTNAME=	rat-3.0
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://cs.ucl.ac.uk/mice/rat/src/
DISTFILES=	rat-3.0.23.tar.gz

MAINTAINER=	mycroft@NetBSD.ORG

DEPENDS+=	tk-8.0p2:../../x11/tk80

RESTRICTED=	"Contains DES encryption"
MIRROR_DISTFILE=no
USE_GMAKE=	yes
MAN1=		rat.1

do-build:
	cd ${WRKSRC} && PREFIX=${PREFIX} MAKE=${MAKE_PROGRAM} ./Build rat

do-install:
	cd ${WRKSRC} && ( \
	 install -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
	    bin/$${USER:=`whoami`}/rat-`uname -s`-`uname -r` \
	    ${LOCALBASE}/bin/rat; \
	 install -c -o ${MANOWN} -g ${MANGRP} -m ${MANMODE} \
	    man/man1/rat.1 ${LOCALBASE}/man/man1/rat.1 )

.include "../../mk/bsd.pkg.mk"
