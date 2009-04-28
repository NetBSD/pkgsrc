# $NetBSD: Makefile,v 1.5 2009/04/28 21:30:09 zafer Exp $
#

DISTNAME=	fgfs-base-1.0.0
PKGNAME=	${DISTNAME:S/fgfs/flightgear/}
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Shared/ \
		http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Shared/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Shared/ 
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.flightgear.org/pub/fgfs/Shared/
COMMENT=	FlightGear Simulator (data files)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/data
NO_BUILD=	yes
USE_LANGUAGES=	# empty
USE_TOOLS+=	pax

FG_SHAREDIR=	${PREFIX}/share/FlightGear

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FG_SHAREDIR}
	(							\
	cd ${WRKSRC};						\
	${FIND} . -type f -name .\* -print|${XARGS} rm -f;	\
	pax -rwppm . ${DESTDIR}${FG_SHAREDIR};		\
	)

.include "../../mk/bsd.pkg.mk"
