# $NetBSD: Makefile,v 1.22 2013/10/19 09:07:10 adam Exp $

MODNAME=		yaz
PECL_VERSION=		1.1.1
PECL_LEGACY_VERSION_SCHEME=	yes
PKGREVISION=		6
CATEGORIES+=		net
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP extension for YAZ

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.yaz}

.include "../../lang/php/ext.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
