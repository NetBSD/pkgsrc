# $NetBSD: Makefile,v 1.13 2018/01/16 09:37:00 wiz Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 6
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
