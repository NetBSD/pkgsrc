# $NetBSD: go-module.mk,v 1.15 2024/05/12 19:45:56 wiz Exp $
#
# This file implements common logic for compiling Go programs in pkgsrc.
#
# === Package-settable variables ===
#
# GO_BUILD_PATTERN (optional)
#	Argument used for 'go install'.
#	In most cases, the default is fine.
#
#	Default:
#		"./...", which means all files below the top-level directory.
#
# GO_MODULE_FILES (optional)
#	List of dependency files to be downloaded from the Go module proxy.
#	Can be filled out from the output of "make show-go-modules" or
#	"make print-go-modules".
#
# GO_EXTRA_MOD_DIRS (optional)
#
# 	List of additional directories in which to look for go.mod files for
# 	the show-go-modules target.
#
# Keywords: go golang
#

# Implementation notes
#
# All packages build-depend on the default Go release. Go packages should be
# revbumped when that package is updated.
#

.include "../../lang/go/version.mk"

GO_BUILD_PATTERN?=	./...
GO_EXTRA_MOD_DIRS?=

MAKE_JOBS_SAFE=		no
INSTALLATION_DIRS+=	bin
USE_TOOLS+=		pax

TOOL_DEPENDS+=		${GO_PACKAGE_DEP}
PRINT_PLIST_AWK+=	/^@pkgdir bin$$/ { next; }

MAKE_ENV+=	GO111MODULE=on GOPATH=${WRKDIR}/.gopath GOPROXY=file://${WRKDIR}/.goproxy
MAKE_ENV+=	GOCACHE=${WRKDIR}/.cache/go-build
MAKE_ENV+=	GOTOOLCHAIN=local

.if !target(do-build)
do-build:
	${RUN} cd ${WRKSRC} && ${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install -v ${GO_BUILD_PATTERN}
.endif

.if !target(do-test)
do-test:
	${RUN} cd ${WRKSRC} && ${_ULIMIT_CMD} ${PKGSRC_SETENV} ${TEST_ENV} ${MAKE_ENV} ${GO} test -v ${GO_BUILD_PATTERN}
.endif

.if !target(do-install)
do-install:
	${RUN} cd ${WRKDIR}/.gopath && [ ! -d bin ] || ${PAX} -rw bin ${DESTDIR}${PREFIX}
.endif

.PHONY: print-go-modules show-go-modules
print-go-modules show-go-modules: ${WRKDIR}/.extract_done
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} https_proxy= GOPROXY= ${GO} mod download -x
.for dir in ${GO_EXTRA_MOD_DIRS}
	${RUN} cd ${dir} && ${PKGSRC_SETENV} ${MAKE_ENV} https_proxy= GOPROXY= ${GO} mod download -x
.endfor
	${RUN} ${PRINTF} '# $$%s$$\n\n' NetBSD
	${RUN} cd ${WRKDIR}/.gopath/pkg/mod/cache/download && ${FIND} . -type f -a \( -name "*.mod" -o -name "*.zip" \) | ${SED} -e 's/\.\//GO_MODULE_FILES+=	/' | ${SORT}

DISTFILES?=	${DEFAULT_DISTFILES}
.for i in ${GO_MODULE_FILES}
DISTFILES+=	${i:C/[\/!]/_/g}
SITES.${i:C/[\/!]/_/g}= -https://proxy.golang.org/${i}
.endfor

.PHONY: post-extract-go
post-extract: post-extract-go
post-extract-go:
.for i in ${GO_MODULE_FILES}
	@${MKDIR} ${WRKDIR}/.goproxy/${i:H}
	@cp ${DISTDIR}/${DIST_SUBDIR}/${i:C/[\/!]/_/g} ${WRKDIR}/.goproxy/${i}
.endfor

.PHONY: pre-clean-go
pre-clean: pre-clean-go
pre-clean-go:
	${RUN} [ -d ${WRKDIR}/.gopath ] && chmod -R +w ${WRKDIR}/.gopath || true

_VARGROUPS+=		go
_PKG_VARS.go=		GO_BUILD_PATTERN GO_MODULE_FILES GO_EXTRA_MOD_DIRS
_USER_VARS.go=		GO_VERSION_DEFAULT
_SYS_VARS.go=		GO GO_VERSION GOVERSSUFFIX GOARCH GOCHAR \
			GOOPT GOTOOLDIR GO_PLATFORM
_DEF_VARS.go=		GO14_VERSION GO19_VERSION GO110_VERSION \
			GO111_VERSION INSTALLATION_DIRS MAKE_JOBS_SAFE \
			NOT_FOR_PLATFORM ONLY_FOR_PLATFORM SSP_SUPPORTED \
			WRKSRC
_USE_VARS.go=		GO_PACKAGE_DEP
_SORTED_VARS.go=	INSTALLATION_DIRS *_FOR_PLATFORM
