# $NetBSD: Makefile,v 1.7 2018/12/13 19:51:49 adam Exp $

MODNAME=	gearman
PECL_VERSION=   2.0.5
DISTNAME=	gearman-${PECL_VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=wcgallego/}
GITHUB_PROJECT=	pecl-gearman
GITHUB_TAG=	${DISTNAME}
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wcgallego/pecl-gearman
COMMENT=	PHP extension for Gearman
LICENSE=	php

WRKSRC=	${WRKDIR}/pecl-gearman-gearman-${PECL_VERSION}

PHP_VERSIONS_ACCEPTED=	70 71 72

CONFIGURE_ARGS+=	--with-gearman=shared,${BUILDLINK_PREFIX.gearmand}

.include "../../devel/gearmand/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
