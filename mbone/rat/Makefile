# $NetBSD: Makefile,v 1.5 1998/05/04 23:42:39 hubertf Exp $
#

DISTNAME=	rat-3.0.24
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://cs.ucl.ac.uk/mice/rat/src/

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
	 ${INSTALL_PROGRAM} \
	    bin/$${USER:=`whoami`}/rat-`uname -s`-`uname -r` \
	    ${LOCALBASE}/bin/rat; \
	 ${INSTALL_MAN} \
	    man/man1/rat.1 ${LOCALBASE}/man/man1/rat.1 )

.include "../../mk/bsd.pkg.mk"
