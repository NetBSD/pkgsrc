# $NetBSD: Makefile,v 1.2 2015/06/25 07:37:58 joerg Exp $

DISTNAME=	${GHNAME}-${GHDATE}-${GHCOMMIT}
PKGNAME=	${GHNAME}-0.4.0.${GHDATE}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=${GHACCOUNT}/${GHNAME}/archive/${GHCOMMIT}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vitalif/Grive2
COMMENT=	Independent open source implementation of Google Drive client
LICENSE=	gnu-gpl-v2

GHACCOUNT=	vitalif
GHNAME=		grive2
GHDATE=		20150531
GHCOMMIT=	06eb1a7df2032144f99473fd812412514834a1ee

WRKSRC=		${WRKDIR}/grive2-${GHCOMMIT}
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
.include "../../devel/libiberty/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
