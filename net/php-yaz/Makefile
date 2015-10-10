# $NetBSD: Makefile,v 1.29 2015/10/10 01:58:17 ryoon Exp $

MODNAME=		yaz
PECL_VERSION=		1.1.9
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
