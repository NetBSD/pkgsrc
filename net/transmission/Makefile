# $NetBSD: Makefile,v 1.28 2021/04/21 13:25:14 adam Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 1
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
