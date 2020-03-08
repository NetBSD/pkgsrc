# $NetBSD: Makefile,v 1.24 2020/03/08 16:50:59 wiz Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 4
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
