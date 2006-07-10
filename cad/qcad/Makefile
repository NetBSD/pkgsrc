# $NetBSD: Makefile,v 1.40 2006/07/10 22:59:26 jlam Exp $
#

DISTNAME=		qcad-2.0.5.0-1-community.src
# what to do about this numbering? RibbonSoft really seems to use four digits
# (there's a 2.0.4.7 for some platforms), though I don't know about the
# thing after the hyphen, which always seems to be 1. Can I use four digits?
PKGNAME=		qcad-2.0.5.0

.include "./Makefile.common"

COMMENT=		2D CAD system

GNU_CONFIGURE=		yes
USE_TOOLS+= 		gmake
USE_LANGUAGES+=		c c++

CONFIGURE_DIRS= 	${WRKSRC}/fparser ${WRKSRC}/dxflib

BUILD_DIRS=		${CONFIGURE_DIRS}
.for _sfx_ in lib cmd actions guiqt
  BUILD_DIRS+=		${WRKSRC}/qcad${_sfx_}
.endfor
BUILD_DIRS+=		${WRKSRC}/qcad

MAKE_ENV+=		QMAKESPEC=${QTDIR}/mkspecs/default
PREPEND_PATH+=		${QTDIR}/bin

# I really want this to be post-*patch* where it makes sense, but QTDIR isn't
# available until after the wrapper phase because it depends on
# BUILDLINK_PREFIX.qt3-libs, which buildlink3 sets.  Nothing is easy.  :) The
# patches have replaced old hardcoded paths with fixed cookies @PREFIX@ and
# @QTDIR@.  The SUBST framework will replace the cookies with the proper
# values.  Quoting invariants: the SUBST framework adds no quoting to the
# SUBST_SED value (not documented but can be gleaned from mk/subst.mk); quoting
# is provided here as follows: the escaped-newline real-newline escaped-newline
# sequence separating individual sed commands is enclosed in ""s so it is not a
# word separator for the shell; sed sees a single trailing blank on the first
# command and a single leading blank on the second, neither of which matters.
# The constant portions of the sed commands are (by inspection) free of shell
# metacharacters; the variable portions ${PREFIX} and ${QTDIR} are subject to
# two layers of quoting: S/=/\=/g ensures that any = in their values will be
# \-escaped (because = has been chosen for the delimiter in the sed s command),
# and then Q ensures that all of that is quoted as necessary to survive the
# shell.

SUBST_CLASSES+= 	paths
SUBST_STAGE.paths=	post-wrapper
SUBST_MESSAGE.paths=	Attending to hard-coded paths.
SUBST_FILES.paths+=	qcadlib/src/engine/rs_system.cpp
SUBST_FILES.paths+=	qcad/src/qc_applicationwindow.cpp
SUBST_SED.paths=	s=@PREFIX@=${PREFIX:S/=/\=/g:Q}=g"\
			${.newline}\
			"s=@QTDIR@=${QTDIR:S/=/\=/g:Q}=g

# Just setting BUILD_DIRS would be adequate if qcad could be built with
# "prepare all" in each module, one by one.  But qcad needs all modules to
# be prepare'd before any can be all'd, so prepare them here in a separate
# loop duplicated from do-build.  The unmodified do-build then takes care
# of the "all".  I didn't see an easier way.
pre-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}for DIR in ${BUILD_DIRS} ; do \
		( cd $${DIR} &&  \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		-f ${MAKEFILE} prepare ) || exit 1 ; done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcad/qcad ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/qcad
	cd ${WRKSRC}/qcad && umask 022 && \
	${PAX} -rwpm data fonts patterns qm ${PREFIX}/share/qcad

.include "../../x11/qt3-libs/buildlink3.mk"
BUILDLINK_DEPENDS.qt3-libs+=	qt3-libs>=3.3.4
.include "../../x11/qt3-tools/buildlink3.mk"
BUILDLINK_DEPENDS.qt3-tools+=	qt3-tools>=3.3.4
BUILDLINK_DEPMETHOD.qt3-tools=	full # uses assistant for help
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
