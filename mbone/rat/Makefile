# $NetBSD: Makefile,v 1.20 2004/01/24 14:00:13 grant Exp $
#

DISTNAME=	rat-3.0.28
CATEGORIES=	mbone
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rat/3.0.28/

MAINTAINER=	mycroft@NetBSD.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rat/
COMMENT=	Robust Audio Tool - multicast audioconferencing

DEPENDS+=	tk>=8.3.2:../../x11/tk

CRYPTO=		yes
USE_GNU_TOOLS+=	make
USE_X11BASE=	yes

USER=		build

do-build:
	cd ${WRKSRC} && USER=${USER} PREFIX=${PREFIX} MAKE=${MAKE_PROGRAM} LDFLAGS="${LDFLAGS}" X11BASE=${X11BASE} LOCALBASE=${LOCALBASE} ./Build rat

do-install:
	cd ${WRKSRC} && ( \
	 ${INSTALL_PROGRAM} \
	    bin/${USER}/rat-${OPSYS}-${OS_VERSION} \
	    ${PREFIX}/bin/rat; \
	 ${INSTALL_MAN} \
	    man/man1/rat.1 ${PREFIX}/man/man1/rat.1 )

.include "../../mk/bsd.pkg.mk"
