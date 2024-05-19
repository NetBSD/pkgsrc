# $NetBSD: Makefile,v 1.85 2024/05/19 03:34:14 mef Exp $

DISTNAME=	klayout-0.29.1
CATEGORIES=	cad
MASTER_SITES=	https://www.klayout.org/downloads/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.klayout.de/
COMMENT=	Simple GDS and OASIS file viewer and Editor
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake bash pax

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
REL_DIR=		bin-release
PLUGINS_DIRS=		db_plugins lay_plugins pymod

PLIST_SUBST+=		PKGVERSION_MAJOR_MINOR=${PKGVERSION_NOREV:C/([0-9]+\.[0-9]+)[.0-9]*/\1/}
# temporarily for 0.28
#PLIST_SUBST+=		PKGVERSION_MAJOR_MINOR=${PKGVERSION_NOREV}.0

.include "../../mk/bsd.prefs.mk"

.if !empty(MAKE_JOBS)
MAKE_JOBS_FLAG=		-option -j${MAKE_JOBS}
.endif

do-build:
	cd ${WRKSRC} && ${MKDIR} ${REL_DIR} && \
	${PKGSRC_SETENV} ${MAKE_ENV} ${BASH} build.sh \
	-python python${PYVERSSUFFIX} \
	-qt5 \
	-qmake ${PREFIX}/qt5/bin/qmake \
	-ruby ${PREFIX}/bin/${RUBY_NAME} \
	${MAKE_JOBS_FLAG} \
	-prefix ${REL_DIR} \
	-rpath ${PREFIX}/lib/klayout

do-install:
	cd ${WRKSRC}/${REL_DIR} && \
	${PAX} -wr libklayout* ${PLUGINS_DIRS} ${INSTALL_LIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${REL_DIR}/strm* \
		${INSTALL_BINDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${REL_DIR}/klayout \
		${INSTALL_BINDIR}

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
