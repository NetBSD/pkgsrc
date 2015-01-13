# $NetBSD: go-package.mk,v 1.2 2015/01/13 21:35:13 bsiegert Exp $
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

.include "../../lang/go/version.mk"

GO_DIST_BASE?=		${GO_SRCPATH}
GO_BUILD_PATTERN?=	${GO_SRCPATH}/...

WRKSRC=			${WRKDIR}/src/${GO_SRCPATH}

BUILD_DEPENDS+=		go-${GO_VERSION}*:../../lang/go

MAKE_JOBS_SAFE=		no
INSTALLATION_DIRS+=	bin gopkg

GOTOOLDIR=		${PREFIX}/go/pkg/tool/${LOWER_OPSYS}_${GOARCH}

post-extract:
	${MKDIR} ${WRKSRC}
	${RM} -fr ${WRKDIR}/`basename ${GO_DIST_BASE}`/.hg
	${MV} ${WRKDIR}/`basename ${GO_DIST_BASE}`/* ${WRKSRC}

do-build:
	env GOPATH=${WRKDIR}:${PREFIX}/gopkg go install -v ${GO_BUILD_PATTERN}

do-install:
	-cd ${WRKDIR} && [ -d bin ] && ${PAX} -rw bin ${DESTDIR}${PREFIX}
	-cd ${WRKDIR} && [ -d pkg ] && ${PAX} -rw src pkg ${DESTDIR}${PREFIX}/gopkg
