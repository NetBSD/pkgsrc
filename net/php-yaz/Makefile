# $NetBSD: Makefile,v 1.34 2016/12/04 05:17:38 ryoon Exp $

MODNAME=		yaz
PECL_VERSION=		1.2.1
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		net

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for YAZ
PKGREVISION=		1
LICENSE=		modified-bsd

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.yaz}

.include "../../lang/php/ext.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
