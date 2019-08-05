# $NetBSD: Makefile,v 1.18 2019/08/05 19:06:49 adam Exp $

DISTNAME=	libunwind-8.0.1.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=llvm/}
GITHUB_PROJECT=	llvm-project
GITHUB_RELEASE=	llvmorg-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://libunwind.llvm.org/
COMMENT=	LLVM libunwind
LICENSE=	modified-bsd

CONFIGURE_DIRS=		${WRKDIR}/build

USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
USE_TOOLS+=		pax
GCC_REQD+=		4.8
SSP_SUPPORTED=		no

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}

CMAKE_ARG_PATH=	${WRKSRC}

INSTALLATION_DIRS=	include

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

post-install:
	cd ${WRKSRC}/include && ${PAX} -rw . ${DESTDIR}${PREFIX}/include

BUILDLINK_DEPMETHOD.llvm=	build
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
