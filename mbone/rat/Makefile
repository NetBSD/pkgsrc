# $NetBSD: Makefile,v 1.8 1998/09/13 17:06:08 garbled Exp $
#

DISTNAME=	rat-3.0.24
CATEGORIES=	mbone
MASTER_SITES=	ftp://cs.ucl.ac.uk/mice/rat/src/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.cs.ucl.ac.uk/mice/rat/

DEPENDS+=	tk-8.0p2:../../x11/tk80

RESTRICTED=	"Contains DES encryption"
MIRROR_DISTFILE=no
USE_GMAKE=	yes
USE_X11=	yes

do-build:
	cd ${WRKSRC} && PREFIX=${PREFIX} MAKE=${MAKE_PROGRAM} LDFLAGS="${LDFLAGS}" X11BASE=${X11BASE} LOCALBASE=${LOCALBASE} ./Build rat

do-install:
	cd ${WRKSRC} && ( \
	 ${INSTALL_PROGRAM} \
	    bin/$${USER:=`whoami`}/rat-`uname -s`-`uname -r` \
	    ${PREFIX}/bin/rat; \
	 ${INSTALL_MAN} \
	    man/man1/rat.1 ${PREFIX}/man/man1/rat.1 )

.include "../../mk/bsd.pkg.mk"
