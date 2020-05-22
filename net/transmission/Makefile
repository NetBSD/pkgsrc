# $NetBSD: Makefile,v 1.26 2020/05/22 10:56:32 adam Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 6
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
