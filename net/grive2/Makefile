# $NetBSD: Makefile,v 1.38 2024/05/29 16:33:53 adam Exp $

DISTNAME=	grive2-0.5.1
PKGREVISION=	13
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
