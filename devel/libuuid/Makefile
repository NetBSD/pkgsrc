# $NetBSD: Makefile,v 1.26 2024/12/28 14:10:23 wiz Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/util-linux/libuuid/}
CATEGORIES=	devel
COMMENT=	Generate unique identifiers for objects
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	--enable-libuuid
CONFIGURE_ARGS+=	--enable-uuidgen

PKGCONFIG_OVERRIDE+=	libuuid/uuid.pc.in

.include "../../mk/bsd.pkg.mk"
