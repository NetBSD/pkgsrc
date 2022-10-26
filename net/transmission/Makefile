# $NetBSD: Makefile,v 1.31 2022/10/26 10:31:52 wiz Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 4
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
