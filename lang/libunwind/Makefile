# $NetBSD: Makefile,v 1.41 2026/03/25 22:56:27 wiz Exp $

.include "../../lang/llvm/version.mk"

PKGNAME=	libunwind-${LLVM_VERSION}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://libunwind.llvm.org/
COMMENT=	LLVM libunwind
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		pax
SSP_SUPPORTED=		no

.include "../../mk/bsd.prefs.mk"

# Configure fails on Alma8 with "/usr/bin/ld: cannot find -lgcc_s".
# The pkg works fine with base GCC.
# The libcxx pkg currently has GCC_REQD=12, while this one is 10.
.if ${OPSYS} != Linux || !exists(/etc/redhat-release)
GCC_REQD+=		10	# must be in sync with libcxx
.endif

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

INSTALLATION_DIRS=	include

.include "../../devel/cmake/build.mk"
BUILDLINK_DEPMETHOD.llvm=	build
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
