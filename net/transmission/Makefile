# $NetBSD: Makefile,v 1.22 2020/01/12 20:20:40 ryoon Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 2
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
