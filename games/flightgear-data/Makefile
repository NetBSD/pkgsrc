# $NetBSD: Makefile,v 1.2.14.1 2012/10/01 19:54:59 tron Exp $

DISTNAME=	FlightGear-data-2.8.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Shared/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Shared/ \
		ftp://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Shared/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.flightgear.org/
COMMENT=	FlightGear Simulator data files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/data
NO_BUILD=		yes
NO_CONFIGURE=		yes

SHARESUBDIR=	share/FlightGear
SHAREDIR=	${PREFIX}/${SHARESUBDIR}
PLIST_SRC=	PLIST ${WRKDIR}/PLIST.F

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}
	# auto-generated PLIST
	rm -f ${WRKDIR}/PLIST.F
	set -e;	cd ${WRKSRC} &&						\
	find . -type d -print | while read d; do			\
		${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}/"$${d}";	\
	done;								\
	find . -type f -print | while read f; do			\
		${INSTALL_DATA} "$${f}" ${DESTDIR}${SHAREDIR}/"$${f}";	\
		${ECHO} ${SHARESUBDIR}/"$${f#./}" >> ${WRKDIR}/PLIST.F;	\
	done;

.include "../../mk/bsd.pkg.mk"
