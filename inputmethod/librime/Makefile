# $NetBSD: Makefile,v 1.46 2026/08/24 08:42:25 adam Exp $

DISTNAME=	librime-1.17.0
PKGREVISION=	1
CATEGORIES=	inputmethod chinese
MASTER_SITES=	${MASTER_SITE_GITHUB:=rime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rime.im/
COMMENT=	Rime input method engine
LICENSE=	modified-bsd

USE_CXX_FEATURES=	c++17 filesystem
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	rime.pc.in

LDFLAGS+=	-lsnappy

.include "options.mk"

.include "../../converters/opencc/buildlink3.mk"
.include "../../databases/leveldb/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/capnproto/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gflags/buildlink3.mk"
.include "../../devel/google-glog/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../textproc/marisa/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
