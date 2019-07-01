# $NetBSD: Makefile,v 1.18 2019/07/01 04:08:43 ryoon Exp $

CONFLICTS+=	Transmission-[0-9]*
PKGREVISION=	11

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
