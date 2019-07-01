# $NetBSD: Makefile,v 1.14 2019/07/01 04:08:40 ryoon Exp $

DISTNAME=	grive2-0.4.1
PKGREVISION=	11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=vitalif/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vitalif/Grive2
COMMENT=	Independent open source implementation of Google Drive client
LICENSE=	gnu-gpl-v2

GITHUB_TAG=v${PKGVERSION_NOREV}

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		manpath
SUBST_MESSAGE.manpath=	Fix manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	bgrive/CMakeLists.txt grive/CMakeLists.txt
SUBST_SED.manpath=	-e 's,DESTINATION share/man,DESTINATION ${PKGMANDIR},g'

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
