# $NetBSD: Makefile,v 1.21 2017/12/08 08:03:35 adam Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/util-linux/libuuid/}
CATEGORIES=	devel
COMMENT=	Generate unique identifiers for objects
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	--enable-libuuid
CONFIGURE_ARGS+=	--enable-uuidgen
PKGCONFIG_OVERRIDE+=	libuuid/uuid.pc.in

.include "../../mk/bsd.pkg.mk"
