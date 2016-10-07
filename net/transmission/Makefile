# $NetBSD: Makefile,v 1.8 2016/10/07 18:26:08 adam Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 1
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
