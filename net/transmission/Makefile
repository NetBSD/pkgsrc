# $NetBSD: Makefile,v 1.11.6.1 2018/01/19 21:33:24 spz Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 6
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
