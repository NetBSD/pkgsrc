# $NetBSD: Makefile,v 1.16 2018/08/16 18:55:08 adam Exp $

CONFLICTS+=	Transmission-[0-9]*
PKGREVISION=	9

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
