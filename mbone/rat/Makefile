# $NetBSD: Makefile,v 1.23 2004/10/03 00:12:57 tv Exp $
#

DISTNAME=	rat-3.0.28
PKGREVISION=	1
CATEGORIES=	mbone
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rat/3.0.28/

MAINTAINER=	mycroft@NetBSD.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rat/
COMMENT=	Robust Audio Tool - multicast audioconferencing

CRYPTO=		yes
USE_BUILDLINK3= yes
USE_GNU_TOOLS+=	make
USE_X11BASE=	yes

USER=		build

post-patch:
	${CP} ${WRKSRC}/Makefile_NetBSD_1 ${WRKSRC}/Makefile_NetBSD_2

do-build:
	cd ${WRKSRC} && USER=${USER} PREFIX=${PREFIX} MAKE=${MAKE_PROGRAM} LDFLAGS="${LDFLAGS}" X11BASE=${X11BASE} LOCALBASE=${LOCALBASE} TCLCONFIG=${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh ./Build rat

do-install:
	cd ${WRKSRC} && ( \
	 ${INSTALL_PROGRAM} \
	    bin/${USER}/rat-${OPSYS}-${OS_VERSION} \
	    ${PREFIX}/bin/rat; \
	 ${INSTALL_MAN} \
	    man/man1/rat.1 ${PREFIX}/man/man1/rat.1 )

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
