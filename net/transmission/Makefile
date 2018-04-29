# $NetBSD: Makefile,v 1.15 2018/04/29 21:32:00 adam Exp $

CONFLICTS+=	Transmission-[0-9]*
PKGREVISION=	8

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
