# $NetBSD: Makefile,v 1.25 2022/01/10 01:46:29 ryoon Exp $

MODNAME=	gearman
PECL_VERSION=	2.1.0
DISTNAME=	gearman-${PECL_VERSION}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=php/}
GITHUB_PROJECT=	pecl-networking-gearman
GITHUB_TAG=	${DISTNAME}
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/php/pecl-networking-gearman
COMMENT=	PHP extension for Gearman
LICENSE=	php

WRKSRC=	${WRKDIR}/pecl-networking-gearman-gearman-${PECL_VERSION}

PHP_VERSIONS_INCOMPATIBLE=	56

CONFIGURE_ARGS+=	--with-gearman=shared,${BUILDLINK_PREFIX.gearmand}

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/gearmand/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
