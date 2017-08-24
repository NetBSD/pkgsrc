# $NetBSD: Makefile,v 1.11 2017/08/24 20:03:37 adam Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 4
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
