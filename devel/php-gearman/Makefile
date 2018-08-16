# $NetBSD: Makefile,v 1.5 2018/08/16 18:54:42 adam Exp $

GITHUB_PROJECT=	pecl-gearman
MODNAME=	gearman
PECL_VERSION=   2.0.3
DISTNAME=	gearman-${PECL_VERSION}
GITHUB_TAG=	gearman-${PKGVERSION_NOREV}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=wcgallego/}
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wcgallego/pecl-gearman
COMMENT=	PHP extension for Gearman
LICENSE=	php

WRKSRC=	${WRKDIR}/pecl-gearman-gearman-${PECL_VERSION}

PHP_VERSIONS_ACCEPTED=	70 71

CONFIGURE_ARGS+=	--with-gearman=shared,${BUILDLINK_PREFIX.gearmand}

.include "../../devel/gearmand/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
