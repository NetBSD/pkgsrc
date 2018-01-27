# $NetBSD: go-package.mk,v 1.11 2018/01/27 15:49:30 rillig Exp $
#
# This file implements common logic for compiling Go programs in pkgsrc.
#
# === Package-settable variables ===
#
# GO_SRCPATH (required)
#	The patch that can be used with "go get" to import the current
#	package. This is usually the URL without the leading protocol.
#
#	Examples:
#		github.com/username/repository
#		gopkg.in/check.v1
#
# GO_DIST_BASE (optional)
#	Path this package extracts to.
#
#	Default:
#		The last path component of ${GO_SRCPATH}
#	Examples:
#		${GITHUB_PROJECT}-${GITHUB_TAG}*
#		${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
#		${DISTNAME}
#
# GO_BUILD_PATTERN (optional)
#	Argument used for 'go install'.
#	In most cases, the default is fine.
#
#	Default:
#		"${GO_SRCPATH}/...", which means all files below GO_SRCPATH.
#
# Keywords: go golang
#

# Implementation notes
#
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

.include "../../lang/go/version.mk"

_GO_DIST_BASE!=		basename ${GO_SRCPATH}
GO_DIST_BASE?=		${_GO_DIST_BASE}
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

.if !target(post-extract)
post-extract:
	${RUN} ${MKDIR} ${WRKSRC}
	${RUN} ${RM} -fr ${WRKDIR}/${GO_DIST_BASE}/.hg
	${RUN} ${MV} ${WRKDIR}/${GO_DIST_BASE}/* ${WRKSRC}
.endif

.if !target(do-build)
do-build:
	${RUN} env GOPATH=${WRKDIR}:${BUILDLINK_DIR}/gopkg go install -v ${GO_BUILD_PATTERN}
.endif

.if !target(do-test)
do-test:
	${RUN} env GOPATH=${WRKDIR}:${BUILDLINK_DIR}/gopkg go test -v ${GO_BUILD_PATTERN}
.endif

.if !target(do-install)
do-install:
	${RUN} cd ${WRKDIR}; [ ! -d bin ] || ${PAX} -rw bin ${DESTDIR}${PREFIX}
	${RUN} cd ${WRKDIR}; [ ! -d pkg ] || ${PAX} -rw src pkg ${DESTDIR}${PREFIX}/gopkg
.endif
