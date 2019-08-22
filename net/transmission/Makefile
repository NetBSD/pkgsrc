# $NetBSD: Makefile,v 1.21 2019/08/22 12:23:42 ryoon Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 1
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
