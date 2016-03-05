# $NetBSD: Makefile,v 1.6 2016/03/05 11:29:12 jperkin Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

PKGREVISION= 1
.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
