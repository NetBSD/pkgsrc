# $NetBSD: Makefile,v 1.11 2008/10/02 13:35:02 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

CONFLICTS+=		wistumbler-gtk-[0-9]*
CONFLICTS+=		wistumbler2-gtk-[0-9]*

CONFIGURE_ARGS+=	--without-gtk

.include "../../mk/bsd.pkg.mk"
