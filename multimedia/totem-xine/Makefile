# $NetBSD: Makefile,v 1.27 2009/02/21 21:16:54 wiz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/totem/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-xine-/}

COMMENT+=	(using Xine)

CONFLICTS+=	totem-[0-9]*

CONFIGURE_ARGS+=	--enable-xine=yes
CONFIGURE_ARGS+=	--disable-browser-plugins

# needed for fake events to keep screensavers out, dubious
.include "../../x11/libXtst/buildlink3.mk"
# XVIDMODE is disabled in the source
#.include "../../x11/libXxf86vm/buildlink3.mk"

.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
