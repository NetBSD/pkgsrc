# $NetBSD: Makefile,v 1.6 1998/06/22 12:47:35 agc Exp $
#

DISTNAME=	rat-3.0.24
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://cs.ucl.ac.uk/mice/rat/src/

MAINTAINER=	mycroft@NetBSD.ORG

DEPENDS+=	tk-8.0p2:../../x11/tk80

RESTRICTED=	"Contains DES encryption"
MIRROR_DISTFILE=no
USE_GMAKE=	yes

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
