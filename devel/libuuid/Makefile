# $NetBSD: Makefile,v 1.25 2023/08/14 05:24:12 wiz Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/util-linux/libuuid/}
PKGREVISION=	2
CATEGORIES=	devel
COMMENT=	Generate unique identifiers for objects
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	--enable-libuuid
CONFIGURE_ARGS+=	--enable-uuidgen

PKGCONFIG_OVERRIDE+=	libuuid/uuid.pc.in

.include "../../mk/bsd.pkg.mk"
