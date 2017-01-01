# $NetBSD: Makefile,v 1.9 2017/01/01 16:06:34 adam Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 2
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
