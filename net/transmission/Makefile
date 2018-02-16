# $NetBSD: Makefile,v 1.14 2018/02/16 12:33:36 wiz Exp $

CONFLICTS+=	Transmission-[0-9]*
PKGREVISION=	7

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
