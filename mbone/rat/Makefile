# $NetBSD: Makefile,v 1.14 2000/08/18 22:46:42 hubertf Exp $
#

DISTNAME=	rat-3.0.28
CATEGORIES=	mbone
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rat/3.0.28/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rat/

DEPENDS+=	tk-8.0.5:../../x11/tk80

RESTRICTED=		"Contains DES encryption"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

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
