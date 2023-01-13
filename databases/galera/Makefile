# $NetBSD: Makefile,v 1.1 2023/01/13 16:08:03 wiz Exp $

DISTNAME=	galera-26.4.13
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=codership/}
GITHUB_TAG=	release_${PKGVERSION_NOREV}
DISTFILES=	${DEFAULT_DISTFILES} 694d6ca47f5eec7873be99b7d6babccf633d1231.tar.gz
SITES.694d6ca47f5eec7873be99b7d6babccf633d1231.tar.gz=	https://github.com/codership/wsrep-API/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/codership/galera/
COMMENT=	Synchronous multi-master replication library
# GPL with openssl exception to allow linking against openssl
LICENSE=	gnu-gpl-v2 AND boost-license

WRKSRC=		${WRKDIR}/galera-release_26.4.13
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CHECK_PORTABILITY_SKIP+=	scripts/mysql/centos/mysqld_safe
CHECK_PORTABILITY_SKIP+=	scripts/mysql/debian/mysqld_safe-5.5

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

post-extract:
	cd ${WRKDIR}/wsrep-* && ${MV} * ${WRKSRC}/wsrep/src/

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/check/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
