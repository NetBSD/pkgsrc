# $NetBSD: Makefile,v 1.2 2020/12/14 17:15:35 tnn Exp $

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

PLIST_SUBST+=	CPU_FEATURES_ARCH=${MACHINE_ARCH:S/i386/x86/:S/x86_64/x86/}

.include "../../mk/bsd.pkg.mk"
