# $NetBSD: Makefile,v 1.33 2021/01/14 12:25:33 mef Exp $

DISTNAME=	klayout-0.26.8
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	http://www.klayout.org/downloads/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.klayout.de/
COMMENT=	Simple GDS and OASIS file viewer and Editor
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake bash

BUILD_DEPENDS+=	rsync-[0-9]*:../../net/rsync
CFLAGS+=	-I${PREFIX}/include/python${PYVERSUFFIX}
NO_CONFIGURE=	yes

CHECK_SHLIBS_SKIP+=	lib/klayout/plugins/streamers/*/unit_tests/* \
			lib/klayout/plugins/tools/net_tracer/unit_tests/*

SUBST_CLASSES+=		rpath
SUBST_MESSAGE.rpath=	Add COMPILER_RPATH_FLAG and PREFIX to NetBSD specific config file
SUBST_FILES.rpath+=	config/Makefile.conf.netbsd-32-gcc-release
SUBST_STAGE.rpath=	pre-configure
SUBST_VARS.rpath=	COMPILER_RPATH_FLAG PREFIX LDFLAGS

BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl

AUTO_MKDIRS=		yes
INSTALL_BINDIR=		${DESTDIR}${PREFIX}/bin
INSTALL_LIBDIR=		${DESTDIR}${PREFIX}/lib/klayout
REL_DIR=		build-release

.include "../../mk/bsd.prefs.mk"

.if !empty(MAKE_JOBS)
MAKE_JOBS_FLAG=		-option -j${MAKE_JOBS}
.endif

do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${BASH} build.sh \
	-python python${PYVERSSUFFIX} \
	-qt5 \
	-qmake ${PREFIX}/qt5/bin/qmake \
	-ruby ${PREFIX}/bin/${RUBY_NAME} \
	${MAKE_JOBS_FLAG} \
	-prefix ${PREFIX} \
	-rpath ${PREFIX}/lib/klayout

do-install:
	cd ${WRKSRC} && \
	rsync     -aH      ${WRKSRC}/${REL_DIR}/libklayout_* \
		${INSTALL_LIBDIR} && \
	rsync     -aH --exclude=\*\.o      ${WRKSRC}/${REL_DIR}/plugins/ \
		${INSTALL_LIBDIR}/plugins/ && \
	rsync     -aH --exclude=\*\.o      ${WRKSRC}/${REL_DIR}/db_plugins/ \
		${INSTALL_LIBDIR}/db_plugins/
	${INSTALL_PROGRAM} ${WRKSRC}/${REL_DIR}/strm* \
		${INSTALL_BINDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${REL_DIR}/klayout \
		${INSTALL_BINDIR}

.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
