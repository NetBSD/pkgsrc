# $NetBSD: Makefile,v 1.25 2005/06/16 06:57:41 jlam Exp $

DISTNAME=		qcad-1.5.4-src
PKGNAME=		qcad-1.5.4
PKGREVISION=		4
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=qcad/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.qcad.org/
COMMENT=		2D CAD System

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}
MAKE_ENV+=		QTDIR=${BUILDLINK_PREFIX.qt3}
INSTALLATION_DIRS=	bin

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

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
