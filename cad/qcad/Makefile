# $NetBSD: Makefile,v 1.11 2003/04/29 21:51:53 jtb Exp $

DISTNAME=		qcad-1.5.4-src
PKGNAME=		qcad-1.5.4
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=qcad/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.qcad.org/
COMMENT=		2D CAD System

WRKSRC=			${WRKDIR}/${PKGNAME}

USE_BUILDLINK2=		# defined
USE_X11=		# defined
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}
MAKE_ENV+=		QTDIR=${BUILDLINK_PREFIX.qt3}

do-configure:
	for f in rappwin.cpp relement.cpp rfonts.cpp rprgdef.h; do	\
		${SED} -e 's:@PREFIX@:'${PREFIX}':g'			\
			-e 's:@X11BASE@:${X11BASE}:g'			\
		 ${WRKSRC}/$$f	> ${WRKSRC}/$$f.tmp			\
		&& ${MV} ${WRKSRC}/$$f.tmp ${WRKSRC}/$$f;		\
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcad ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/qcad
	cd ${WRKSRC} && ${PAX} -rw AUTHORS COPYING README TODO cur doc	\
		examples fonts hatches libraries messages po xpm	\
		${PREFIX}/share/qcad

.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
