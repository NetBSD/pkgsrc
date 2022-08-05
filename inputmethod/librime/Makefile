# $NetBSD: Makefile,v 1.28 2022/08/05 13:02:35 adam Exp $

DISTNAME=	librime-1.7.3
CATEGORIES=	inputmethod chinese
MASTER_SITES=	${MASTER_SITE_GITHUB:=rime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rime.im/
COMMENT=	Rime input method engine
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

LDFLAGS+=	-lsnappy

PKGCONFIG_OVERRIDE+=	rime.pc.in

.include "options.mk"

.include "../../converters/opencc/buildlink3.mk"
.include "../../databases/leveldb/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/capnproto/buildlink3.mk"
.include "../../devel/gflags/buildlink3.mk"
.include "../../devel/google-glog/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../textproc/marisa/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
