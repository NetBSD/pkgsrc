# $NetBSD: Makefile,v 1.35 2024/03/01 22:14:58 bacon Exp $

.include "../../lang/llvm/version.mk"

DISTNAME=	libunwind-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://libunwind.llvm.org/
COMMENT=	LLVM libunwind
LICENSE=	apache-2.0

# libunwind requires libcxx source code to build
LIBCXX=		libcxx-${LLVM_VERSION}.src
EXTRA_DIST+=	${LIBCXX}${EXTRACT_SUFX}

SITES.${LIBCXX}${EXTRACT_SUFX}=	\
	${MASTER_SITES:=${GITHUB_PROJECT}/releases/download/${GITHUB_RELEASE}/}

USE_CXX_FEATURES+=	c++11
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

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

INSTALLATION_DIRS=	include

post-extract:
	${LN} -f -s ${WRKDIR}/${LIBCXX} ${WRKDIR}/libcxx

post-install:
	cd ${WRKSRC}/include && ${PAX} -rw . ${DESTDIR}${PREFIX}/include

.include "../../devel/cmake/build.mk"
BUILDLINK_DEPMETHOD.llvm=	build
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
