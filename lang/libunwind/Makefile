# $NetBSD: Makefile,v 1.3 2016/11/14 20:15:33 ryoon Exp $

DISTNAME=	libunwind-3.9.0.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
#MASTER_SITES=	http://llvm.org/pre-releases/3.8.0/rc2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libunwind.llvm.org/
COMMENT=	LLVM libunwind
LICENSE=	modified-bsd

CONFIGURE_DIRS=		${WRKDIR}/build

USE_TOOLS+=		pax
USE_LANGUAGES=		c c++
USE_CMAKE=		yes
GCC_REQD+=		4.8

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=g++

CMAKE_ARG_PATH=	${WRKSRC}

INSTALLATION_DIRS=	include

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

post-install:
	cd ${WRKSRC}/include && ${PAX} -rw . ${DESTDIR}${PREFIX}/include

BUILDLINK_DEPMETHOD.llvm=	build
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
