# $NetBSD: Makefile,v 1.12 2018/01/01 21:18:49 adam Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 5
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
