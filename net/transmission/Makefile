# $NetBSD: Makefile,v 1.10 2017/04/30 01:21:58 ryoon Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 3
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
