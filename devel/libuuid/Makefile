# $NetBSD: Makefile,v 1.22 2017/12/12 20:52:19 maya Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/util-linux/libuuid/}
CATEGORIES=	devel
COMMENT=	Generate unique identifiers for objects
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	--enable-libuuid
CONFIGURE_ARGS+=	--enable-uuidgen

# netbsd libintl lacks _nl_expand_alias, resulting in NLS being
# disabled. for consistency, disable for all
CONFIGURE_ARGS+=	--disable-nls

PKGCONFIG_OVERRIDE+=	libuuid/uuid.pc.in

.include "../../mk/bsd.pkg.mk"
