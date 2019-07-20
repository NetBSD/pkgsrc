# $NetBSD: Makefile,v 1.19 2019/07/20 22:46:42 wiz Exp $

CONFLICTS+=	Transmission-[0-9]*
PKGREVISION=	12

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
