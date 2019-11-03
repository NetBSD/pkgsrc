# $NetBSD: Makefile,v 1.12 2019/11/03 10:39:28 rillig Exp $

MODNAME=	gearman
PECL_VERSION=	2.0.5
DISTNAME=	gearman-${PECL_VERSION}
PKGREVISION=	4
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

PHP_VERSIONS_ACCEPTED=	71 72

CONFIGURE_ARGS+=	--with-gearman=shared,${BUILDLINK_PREFIX.gearmand}

.include "../../devel/gearmand/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
