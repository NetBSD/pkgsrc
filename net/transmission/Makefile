# $NetBSD: Makefile,v 1.20 2019/07/20 23:14:40 wiz Exp $

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
