# $NetBSD: Makefile,v 1.17 2018/12/13 19:52:18 adam Exp $

CONFLICTS+=	Transmission-[0-9]*
PKGREVISION=	10

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
