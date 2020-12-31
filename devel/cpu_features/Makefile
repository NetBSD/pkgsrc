# $NetBSD: Makefile,v 1.4 2020/12/31 10:56:27 nia Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	cpu_features-0.6.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/cpu_features/
COMMENT=	Cross platform C99 library to get CPU features at runtime
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARGS+=	-DBUILD_PIC=ON

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PLIST_SUBST+=		CPU_FEATURES_ARCH=x86
.elif !empty(MACHINE_ARCH:M*aarch64*)
PLIST_SUBST+=		CPU_FEATURES_ARCH=aarch64
.elif !empty(MACHINE_ARCH:M*powerpc*)
PLIST_SUBST+=		CPU_FEATURES_ARCH=ppc
.elif !empty(MACHINE_ARCH:M*arm*)
PLIST_SUBST+=		CPU_FEATURES_ARCH=arm
.elif !empty(MACHINE_ARCH:M*mips*)
PLIST_SUBST+=		CPU_FEATURES_ARCH=mips
.else
PKG_FAIL_REASON+=	"${MACHINE_ARCH} unsupported, see CMakeLists.txt"
.endif

.include "../../mk/bsd.pkg.mk"
