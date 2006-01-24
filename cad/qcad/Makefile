# $NetBSD: Makefile,v 1.33 2006/01/24 07:31:57 wiz Exp $

DISTNAME=		qcad-1.5.4-src
PKGNAME=		qcad-1.5.4
PKGREVISION=		5
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=qcad/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.qcad.org/
COMMENT=		2D CAD System

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH:Q}
MAKE_ENV+=		QTDIR=${BUILDLINK_PREFIX.qt3}
INSTALLATION_DIRS=	bin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
QCAD_OPSYS = LINUX
.elif ${OPSYS} == "SunOS"
QCAD_OPSYS = SOLARIS
.elif !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly"
QCAD_OPSYS = BSD
.elif !empty(OPSYS:MIRIX)
QCAD_OPSYS = IRIX
.else
QCAD_OPSYS = UNKNOWN
PKG_FAIL_REASON+=	"Unknown operating system for ${PKGNAME}"
.endif

do-configure:
	for f in rappwin.cpp relement.cpp rfonts.cpp rprgdef.h; do	\
		${SED} -e 's:@PREFIX@:'${PREFIX}':g'			\
			-e 's:@X11BASE@:${X11BASE}:g'			\
			-e 's:@OPSYS@:${QCAD_OPSYS}:g'			\
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
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
