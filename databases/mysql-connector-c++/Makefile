# $NetBSD: Makefile,v 1.14 2025/11/10 07:36:57 jnemeth Exp $

DISTNAME=	mysql-connector-c++-9.5.0-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	databases
#MASTER_SITES=	https://dev.mysql.com/get/Downloads/Connector-C++/
MASTER_SITES=	${MASTER_SITE_GITHUB:=mysql/}
GITHUB_PROJECT=	mysql-connector-cpp
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.mysql.com/downloads/connector/cpp/
COMMENT=	Standardized MySQL database driver for C++ development
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

post-install:
	${RM} ${DESTDIR}${PREFIX}/INFO_BIN
	${RM} ${DESTDIR}${PREFIX}/INFO_SRC

.include "../../devel/cmake/build.mk"
.include "../../mk/atomic64.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
