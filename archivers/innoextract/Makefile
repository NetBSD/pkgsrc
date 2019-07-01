# $NetBSD: Makefile,v 1.14 2019/07/01 04:07:54 ryoon Exp $

DISTNAME=	innoextract-1.7
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	http://constexpr.org/innoextract/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://constexpr.org/innoextract/
COMMENT=	Tool to unpack installers created by Inno Setup
LICENSE=	zlib

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/${PKGMANDIR}
CMAKE_ARGS+=	-DUSE_CXX11=OFF

.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
