# $NetBSD: Makefile,v 1.30 2021/12/08 16:06:08 adam Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 3
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
