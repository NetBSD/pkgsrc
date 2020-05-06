# $NetBSD: Makefile,v 1.25 2020/05/06 14:04:58 adam Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 5
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
