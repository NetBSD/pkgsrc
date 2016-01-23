# $NetBSD: go-package.mk,v 1.8 2016/01/23 12:42:57 rillig Exp $
#
# This file implements common logic for compiling Go programs in pkgsrc.
# The compiled Go code is tied to a specific compiler version, and the
# compilation is fast. So the plan is:
#
# 1. Compile everything.
# 2. Install binaries into bin/.
# 3. Install source code and packages into a separate gopkg tree.
#
# In the future, we may implement buildlink by creating a separate tree during
# the build and linking only the packages explicitly mentioned in dependencies
# there.
#
# All packages build-depend on the "master" Go release. Go packages
# need to be revbumped when lang/go is updated.
#
# Packages using this should set GO_SRCPATH to the path that could
# be used with "go get" (usually the URL without the leading protocol).
#
# === Package-settable variables ===
#
# GO_SRCPATH
#	Path used for go 'import' lines in source code.
#
# GO_DIST_BASE
#	Path this package extracts to; only set it if it's not the same
#	as GO_SRCPATH.
#
# GO_BUILD_PATTERN
#	Argument used for 'go install'
#	Defaults to "${GO_SRCPATH}/..." which means all files
#	below GO_SRCPATH.
#
# Keywords: go
#

.include "../../lang/go/version.mk"

GO_DIST_BASE?=		${GO_SRCPATH}
GO_BUILD_PATTERN?=	${GO_SRCPATH}/...

WRKSRC=			${WRKDIR}/src/${GO_SRCPATH}

BUILD_DEPENDS+=		go-${GO_VERSION}*:../../lang/go

MAKE_JOBS_SAFE=		no
INSTALLATION_DIRS+=	bin gopkg
USE_TOOLS+=		pax

GO_PLATFORM=		${LOWER_OPSYS}_${GOARCH}
GOTOOLDIR=		${PREFIX}/go/pkg/tool/${GO_PLATFORM}

PRINT_PLIST_AWK+=	{ gsub(/${GO_PLATFORM}/, \
			"$${GO_PLATFORM}"); \
			print; next; }

post-extract:
	${RUN} ${MKDIR} ${WRKSRC}
	${RUN} ${RM} -fr ${WRKDIR}/`basename ${GO_DIST_BASE}`/.hg
	${RUN} ${MV} ${WRKDIR}/`basename ${GO_DIST_BASE}`/* ${WRKSRC}

do-build:
	${RUN} env GOPATH=${WRKDIR}:${BUILDLINK_DIR}/gopkg go install -v ${GO_BUILD_PATTERN}

.if !target(do-test)
do-test:
	${RUN} env GOPATH=${WRKDIR}:${BUILDLINK_DIR}/gopkg go test -v ${GO_BUILD_PATTERN}
.endif

do-install:
	${RUN} cd ${WRKDIR}; [ ! -d bin ] || ${PAX} -rw bin ${DESTDIR}${PREFIX}
	${RUN} cd ${WRKDIR}; [ ! -d pkg ] || ${PAX} -rw src pkg ${DESTDIR}${PREFIX}/gopkg
