# $NetBSD: Makefile,v 1.7 2019/07/01 04:07:46 ryoon Exp $

DISTNAME=	mariadb-connector-c-3.0.6
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=MariaDB/}

MAINTAINER=	fhajny@NetBSD.org
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
