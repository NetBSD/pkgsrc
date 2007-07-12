# $NetBSD: Makefile,v 1.1.1.1 2007/07/12 20:05:28 drochner Exp $
#

DISTNAME=	fgfs-base-0.9.10
PKGNAME=	${DISTNAME:S/fgfs/flightgear/}
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Shared/ \
		ftp://ftp.sunsite.org.uk/sites/ftp.flightgear.org/flightgear-ftp/Shared/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Shared/ \
		http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Shared/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Shared/ \
		ftp://obgyn.edu.pl/fgfs/Shared/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.flightgear.org/pub/fgfs/Shared/
COMMENT=	FlightGear Simulator (data files)

WRKSRC=		${WRKDIR}/data
NO_BUILD=	yes
USE_LANGUAGES=	# empty

FG_SHAREDIR=	${PREFIX}/share/FlightGear

do-install:
.if !exists(${FG_SHAREDIR})
	${INSTALL_DATA_DIR} ${FG_SHAREDIR}
.endif
	(						    \
	cd ${WRKSRC};					    \
	${FIND} . -type f -name .\* -print|${XARGS} rm -f;  \
	${PAX} -rwppm . ${FG_SHAREDIR};			    \
	)

.include "../../mk/bsd.pkg.mk"
