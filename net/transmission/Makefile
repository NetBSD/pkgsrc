# $NetBSD: Makefile,v 1.29 2021/09/29 19:01:11 adam Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 2
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
