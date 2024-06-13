# $NetBSD: version.mk,v 1.210 2024/06/13 12:55:15 bsiegert Exp $

#
# If bsd.prefs.mk is included before go-package.mk in a package, then this
# file must be included directly in the package prior to bsd.prefs.mk.
#
.include "go-vars.mk"

GO122_VERSION=	1.22.4
GO121_VERSION=	1.21.11
GO120_VERSION=	1.20.14
GO119_VERSION=	1.19.13
GO118_VERSION=	1.18.10
GO14_VERSION=	1.4.3

.include "../../mk/bsd.prefs.mk"

GO_VERSION_DEFAULT?=	122

.if defined(GO_VERSION_REQD)
GOVERSSUFFIX=		${GO_VERSION_REQD}
.elif !empty(GO_VERSION_DEFAULT)
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
# go118 hardcodes GOARCH=arm64 even when running in an x86_64 chroot
.  if ${OPSYS} == "Darwin"
GOOPT+=			GOHOSTARCH=amd64
.  endif
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

.if ${OPSYS} == "SunOS" && ${OS_VARIANT} != "Solaris"
GO_PLATFORM=		illumos_${GOARCH}
.else
GO_PLATFORM=		${LOWER_OPSYS}_${GOARCH}
.endif

PLIST_SUBST+=		GO_PLATFORM=${GO_PLATFORM:Q} GOARCH=${GOARCH:Q}
PLIST_SUBST+=		GOCHAR=${GOCHAR:Q}

PRINT_PLIST_AWK+=	{ sub("/${GO_PLATFORM}/", "/$${GO_PLATFORM}/") }

TOOLS_CREATE+=		go
TOOLS_PATH.go=		${GO}
