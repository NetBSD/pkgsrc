# $NetBSD: Makefile,v 1.26 2023/10/15 20:34:41 triaxx Exp $

DISTNAME=	innoextract-1.9
PKGREVISION=	7
CATEGORIES=	archivers
MASTER_SITES=	https://constexpr.org/innoextract/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://constexpr.org/innoextract/
COMMENT=	Tool to unpack installers created by Inno Setup
LICENSE=	zlib

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

OBJDIR=		../build
CONFIGURE_DIRS=	${OBJDIR}
CMAKE_ARG_PATH=	../${DISTNAME}

CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/${PKGMANDIR}
CMAKE_ARGS+=	-DSET_OPTIMIZATION_FLAGS=OFF

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
