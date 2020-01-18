# $NetBSD: Makefile,v 1.23 2020/01/18 21:50:27 jperkin Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 3
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
