# $NetBSD: Makefile,v 1.4 2018/09/18 08:41:33 fhajny Exp $

DISTNAME=	mariadb-connector-c-3.0.6
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=MariaDB/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/MariaDB/mariadb-connector-c/
COMMENT=	MariaDB Connector/C library
LICENSE=	gnu-lgpl-v2.1

GITHUB_PROJECT=	mariadb-connector-c
GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

.include "options.mk"

CMAKE_ARGS+=	-DWITH_EXTERNAL_ZLIB=ON

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
