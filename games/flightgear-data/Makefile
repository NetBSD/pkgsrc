# $NetBSD: Makefile,v 1.9 2019/06/24 10:59:42 nia Exp $

VERSION=	2018.3.2
DISTNAME=	FlightGear-${VERSION}-data
PKGNAME=	flightgear-data-${VERSION}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flightgear/release-2018.3/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.flightgear.org/
COMMENT=	FlightGear Simulator data files
LICENSE=	gnu-gpl-v2

UNLIMIT_RESOURCES+=	cputime

WRKSRC=			${WRKDIR}/fgdata
NO_BUILD=		yes
NO_CONFIGURE=		yes

PLIST_SRC=	PLIST ${WRKDIR}/PLIST.F

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/FlightGear
	# auto-generated PLIST
	rm -f ${WRKDIR}/PLIST.F
	set -e;	cd ${WRKSRC} &&						\
	find . -type d -print | while read d; do			\
		${INSTALL_DATA_DIR} 					\
		    ${DESTDIR}${PREFIX}/lib/FlightGear/"$${d}";		\
	done;								\
	find . -type f -print | while read f; do			\
		${INSTALL_DATA} "$${f}" 				\
		    ${DESTDIR}${PREFIX}/lib/FlightGear/"$${f}";		\
		${ECHO} lib/FlightGear/"$${f#./}" >> ${WRKDIR}/PLIST.F;	\
	done;

.include "../../mk/bsd.pkg.mk"
