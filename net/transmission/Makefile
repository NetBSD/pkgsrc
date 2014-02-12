# $NetBSD: Makefile,v 1.4 2014/02/12 23:18:26 tron Exp $

PKGREVISION=	1
CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--without-gtk

.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
