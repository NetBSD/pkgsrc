# $NetBSD: Makefile,v 1.1 2013/03/02 19:33:29 wiz Exp $

PKGREVISION=		1

CONFLICTS+=	Transmission-[0-9]*

pre-configure:
	touch ${WRKSRC}/po/Makefile

CONFIGURE_ARGS+=	--without-gtk

.include "../../net/transmission/Makefile.common"
.include "../../mk/bsd.pkg.mk"
