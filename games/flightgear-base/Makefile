# $NetBSD: Makefile,v 1.6 2010/04/17 16:03:02 zafer Exp $
#

DISTNAME=	fgfs-base-1.0.0
PKGNAME=	${DISTNAME:S/fgfs/flightgear/}
CATEGORIES=	games
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Shared/ \
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
