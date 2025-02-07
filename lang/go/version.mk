# $NetBSD: version.mk,v 1.224 2025/02/07 10:17:49 bsiegert Exp $

#
# If bsd.prefs.mk is included before go-package.mk in a package, then this
# file must be included directly in the package prior to bsd.prefs.mk.
#
.include "go-vars.mk"

GO123_VERSION=	1.23.6
GO122_VERSION=	1.22.12
GO121_VERSION=	1.21.13
GO120_VERSION=	1.20.14
GO119_VERSION=	1.19.13
GO118_VERSION=	1.18.10
GO14_VERSION=	1.4.3

.include "../../mk/bsd.prefs.mk"

GO_VERSION_DEFAULT?=	123

.if defined(GO_VERSION_REQD)
GOVERSSUFFIX=		${GO_VERSION_REQD}
.elif !empty(GO_VERSION_DEFAULT)
GOVERSSUFFIX=		${GO_VERSION_DEFAULT}
.endif

# How to find the Go tool
GO=			${TOOLBASE}/go${GOVERSSUFFIX}/bin/go

# Build dependency for Go
GO_PACKAGE_DEP=		go${GOVERSSUFFIX}-${GO${GOVERSSUFFIX}_VERSION}*:../../lang/go${GOVERSSUFFIX}

#ONLY_FOR_PLATFORM?=	*-*-i386 *-*-x86_64 *-*-earmv[67]hf *-*-aarch64

NOT_FOR_PLATFORM=	SunOS-*-i386

GOARCH.aarch64=		arm64
GOARCH.earmv6hf=	arm
GOARCH.earmv7hf=	arm
GOARCH.i386=		386
GOARCH.powerpc64=	ppc64
GOARCH.powerpc64le=	ppc64le
GOARCH.powerpc=		ppc
GOARCH.x86_64=		amd64

GOCHAR.earmv6hf=	5
GOCHAR.earmv7hf=	5
GOCHAR.i386=		8
GOCHAR.x86_64=		6

GOOPT.aarch64=		GOARM=7
GOOPT.earmv6hf=		GOARM=6
GOOPT.earmv7hf=		GOARM=7

GOARCH=			${GOARCH.${MACHINE_ARCH}:U${MACHINE_ARCH}}
NATIVE_GOARCH=		${GOARCH.${NATIVE_MACHINE_ARCH}:U${NATIVE_MACHINE_ARCH}}

GOCHAR=			${GOCHAR.${MACHINE_ARCH}:U}

GOOPT=			${GOOPT.${MACHINE_ARCH}:U}

# go118 hardcodes GOARCH=arm64 even when running in an x86_64 chroot.
# GOHOSTARCH is being misdetected as arm on NetBSD. Unclear why.
.if (${OPSYS} == "Darwin" && ${NATIVE_MACHINE_ARCH} == "x86_64") || \
    ${MACHINE_ARCH} == "aarch64" || \
    ${USE_CROSS_COMPILE:tl} == "yes"
GOOPT+=			GOHOSTARCH=${NATIVE_GOARCH}
.endif

.if ${OPSYS} == "SunOS" && ${OS_VARIANT} != "Solaris"
GOOS=			illumos
.else
GOOS=			${LOWER_OPSYS}
.endif
GO_PLATFORM=		${GOOS}_${GOARCH}

.if ${NATIVE_OPSYS} == "Sunos" && ${NATIVE_OS_VARIANT} != "Solaris"
NATIVE_GOOS=		illumos
.else
NATIVE_GOOS=		${NATIVE_LOWER_OPSYS}
.endif
NATIVE_GO_PLATFORM=	${NATIVE_GOOS}_${NATIVE_GOARCH}

PLIST_SUBST+=		GO_PLATFORM=${GO_PLATFORM:Q} GOARCH=${GOARCH:Q}
PLIST_SUBST+=		GOCHAR=${GOCHAR:Q}

PRINT_PLIST_AWK+=	{ sub("/${GO_PLATFORM}/", "/$${GO_PLATFORM}/") }

TOOLS_CREATE+=		go
TOOLS_PATH.go=		${GO}

.if ${USE_CROSS_COMPILE:tl} == "yes"
GOOPT+=			GOARCH=${GOARCH}
GOOPT+=			GOOS=${LOWER_OPSYS}
GOOPT+=			CC=${NATIVE_CC:Q}
GOOPT+=			CC_FOR_TARGET=${CC:Q}
GOOPT+=			CXX_FOR_TARGET=${CXX:Q}
.endif
