# $NetBSD: Makefile,v 1.3 2018/08/16 18:54:28 adam Exp $

DISTNAME=	mariadb-connector-c-3.0.3
PKGREVISION=	2
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
