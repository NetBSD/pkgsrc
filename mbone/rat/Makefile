# $NetBSD: Makefile,v 1.12 1999/02/20 22:48:35 hubertf Exp $
#

DISTNAME=	rat-3.0.28
CATEGORIES=	mbone
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rat/3.0.28/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rat/

DEPENDS+=	tk-8.0p2:../../x11/tk80

RESTRICTED=	"Contains DES encryption"
MIRROR_DISTFILE=no
USE_GMAKE=	yes
USE_X11BASE=	yes

do-build:
	cd ${WRKSRC} && PREFIX=${PREFIX} MAKE=${MAKE_PROGRAM} LDFLAGS="${LDFLAGS}" X11BASE=${X11BASE} LOCALBASE=${LOCALBASE} ./Build rat

do-install:
	cd ${WRKSRC} && ( \
	 ${INSTALL_PROGRAM} \
	    bin/$${USER:=`whoami`}/rat-${OPSYS}-${OS_VERSION} \
	    ${PREFIX}/bin/rat; \
	 ${INSTALL_MAN} \
	    man/man1/rat.1 ${PREFIX}/man/man1/rat.1 )

.include "../../mk/bsd.pkg.mk"
