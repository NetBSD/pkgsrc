# $NetBSD: Makefile,v 1.56 2013/02/16 11:20:29 wiz Exp $
#

DISTNAME=		qcad-2.0.5.0-1-community.src
# what to do about this numbering? RibbonSoft really seems to use four digits
# (there's a 2.0.4.7 for some platforms), though I don't know about the
# thing after the hyphen, which always seems to be 1. Can I use four digits?
PKGNAME=		qcad-2.0.5.0
PKGREVISION=		7

.include "./Makefile.common"

COMMENT=		2D CAD system

GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf gmake pax
USE_LANGUAGES=		c c++

CONFIGURE_DIRS=		fparser dxflib

BUILD_DIRS=		${CONFIGURE_DIRS}
BUILD_DIRS+=		qcadlib qcadcmd qcadactions qcadguiqt qcad

MAKE_ENV+=		QMAKESPEC=${QTDIR}/mkspecs/default
PREPEND_PATH+=		${QTDIR}/bin

# I really want this to be post-*patch* where it makes sense, but QTDIR isn't
# available until after the wrapper phase because it depends on
# BUILDLINK_PREFIX.qt3-libs, which buildlink3 sets.  Nothing is easy.  :) The
# patches have replaced old hardcoded paths with fixed cookies @PREFIX@ and
# @QTDIR@.  The SUBST framework will replace the cookies with the proper
# values.
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Attending to hard-coded paths.
SUBST_FILES.paths+=	qcadlib/src/engine/rs_system.cpp
SUBST_FILES.paths+=	qcad/src/qc_applicationwindow.cpp
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@QTDIR@,${QTDIR},g'

post-patch:
	cd ${WRKSRC}/fparser && autoconf
	cd ${WRKSRC}/dxflib && autoconf

# Just setting BUILD_DIRS would be adequate if qcad could be built with
# "prepare all" in each module, one by one.  But qcad needs all modules to
# be prepare'd before any can be all'd, so prepare them here in a separate
# loop duplicated from do-build.  The unmodified do-build then takes care
# of the "all".  I didn't see an easier way.
pre-build:
	${RUN} ${_ULIMIT_CMD}						\
	for d in ${BUILD_DIRS}; do					\
		cd ${WRKSRC}; cd "$$d";					\
		${BUILD_MAKE_CMD} prepare;				\
	done

INSTALLATION_DIRS=	bin share/qcad

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcad/qcad ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/qcad && umask 022 && \
	pax -rwpm data fonts patterns qm ${DESTDIR}${PREFIX}/share/qcad

.include "../../x11/qt3-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt3-libs+=	qt3-libs>=3.3.4
.include "../../x11/qt3-tools/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt3-tools+=	qt3-tools>=3.3.4
BUILDLINK_DEPMETHOD.qt3-tools=	full # uses assistant for help
.include "../../mk/bsd.pkg.mk"
