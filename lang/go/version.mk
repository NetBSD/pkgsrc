# $NetBSD: version.mk,v 1.103 2020/11/08 20:38:09 bsiegert Exp $

#
# If bsd.prefs.mk is included before go-package.mk in a package, then this
# file must be included directly in the package prior to bsd.prefs.mk.
#
.include "go-vars.mk"

GO115_VERSION=	1.15.4
GO114_VERSION=	1.14.11
GO113_VERSION=	1.13.15
GO110_VERSION=	1.10.8
GO19_VERSION=	1.9.7
GO14_VERSION=	1.4.3

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OS_VERSION:M6.*}
# 1.9 is the last Go version to support NetBSD 6
GO_VERSION_DEFAULT?=	19
.elif ${OPSYS} == "Darwin" && ${OS_VERSION:R} < 14
# go 1.11 removed support for osx 10.8 and 10.9
# https://github.com/golang/go/issues/23122
# darwin version 13.4 is osx 10.9.5
GO_VERSION_DEFAULT?=	110
.else
GO_VERSION_DEFAULT?=	115
.endif

.if !empty(GO_VERSION_DEFAULT)
GOVERSSUFFIX=		${GO_VERSION_DEFAULT}
.endif

# How to find the Go tool
GO=			${PREFIX}/go${GOVERSSUFFIX}/bin/go

# Build dependency for Go
GO_PACKAGE_DEP=		go${GOVERSSUFFIX}-${GO${GOVERSSUFFIX}_VERSION}*:../../lang/go${GOVERSSUFFIX}

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-earmv[67]hf *-*-aarch64
NOT_FOR_PLATFORM=	SunOS-*-i386
.if ${MACHINE_ARCH} == "i386"
GOARCH=			386
GOCHAR=			8
.elif ${MACHINE_ARCH} == "x86_64"
GOARCH=			amd64
GOCHAR=			6
.elif ${MACHINE_ARCH} == "earmv6hf" || ${MACHINE_ARCH} == "earmv7hf"
GOARCH=			arm
GOCHAR=			5
.elif ${MACHINE_ARCH} == "aarch64"
GOARCH=			arm64
GOOPT=			GOARM=7
# GOHOSTARCH is being misdetected as arm on NetBSD. Unclear why.
GOOPT+=			GOHOSTARCH=arm64
.endif
.if ${MACHINE_ARCH} == "earmv6hf"
GOOPT=			GOARM=6
.elif ${MACHINE_ARCH} == "earmv7hf"
GOOPT=			GOARM=7
.endif
GO_PLATFORM=		${LOWER_OPSYS}_${GOARCH}
PLIST_SUBST+=		GO_PLATFORM=${GO_PLATFORM:Q} GOARCH=${GOARCH:Q}
PLIST_SUBST+=		GOCHAR=${GOCHAR:Q}

PRINT_PLIST_AWK+=	{ sub("/${GO_PLATFORM}/", "/$${GO_PLATFORM}/") }

TOOLS_CREATE+=		go
TOOLS_PATH.go=		${GO}
