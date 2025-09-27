# $NetBSD: Makefile,v 1.47 2025/09/27 09:57:32 wiz Exp $

DISTNAME=	grive2-0.5.1
PKGREVISION=	21
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=vitalif/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vitalif/Grive2
COMMENT=	Independent open source implementation of Google Drive client
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config bash:run
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

SUBST_CLASSES+=		manpath
SUBST_MESSAGE.manpath=	Fix manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	grive/CMakeLists.txt
SUBST_SED.manpath=	-e 's,DESTINATION share/man,DESTINATION ${PKGMANDIR},g'

REPLACE_BASH+=	systemd/grive-sync.sh

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
