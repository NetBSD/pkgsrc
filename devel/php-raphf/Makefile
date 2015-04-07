# $NetBSD: Makefile,v 1.1 2015/04/07 00:21:24 rodent Exp $

MODNAME=	raphf
PECL_VERSION=	1.0.4
CATEGORIES=	devel

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/raphf
COMMENT=	Resource and persistent handles factory
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
