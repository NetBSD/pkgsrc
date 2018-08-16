# $NetBSD: Makefile,v 1.14 2018/08/16 18:55:06 adam Exp $

DISTNAME=	${GHNAME}-${GHDATE}-${GHCOMMIT}
PKGNAME=	${GHNAME}-0.3.0.${GHDATE}
PKGREVISION=	11
CATEGORIES=	net
MASTER_SITES=	https://github.com/${GHACCOUNT}/${GHNAME}/archive/${GHCOMMIT}/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.lbreda.com/grive/start
COMMENT=	Independent open source implementation of Google Drive client
LICENSE=	gnu-gpl-v2

GHACCOUNT=	Grive
GHNAME=		grive
GHDATE=		20130502
GHCOMMIT=	27817e835fe115ebbda5410ec904aa49a2ad01f1

WRKSRC=		${WRKDIR}/grive-${GHCOMMIT}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++11

SUBST_CLASSES+=		disableqt
SUBST_MESSAGE.disableqt=Disable QT frontend
SUBST_STAGE.disableqt=	pre-configure
SUBST_FILES.disableqt=	CMakeLists.txt
SUBST_SED.disableqt=	-e '/ bgrive/d'

SUBST_CLASSES+=		manpath
SUBST_MESSAGE.manpath=	Fix manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	bgrive/CMakeLists.txt grive/CMakeLists.txt
SUBST_SED.manpath=	-e 's,DESTINATION share/man,DESTINATION ${PKGMANDIR},g'

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/libiberty/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
