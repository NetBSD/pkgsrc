# $NetBSD: Makefile,v 1.20 2008/03/07 07:06:17 wiz Exp $
#

.include "../../multimedia/totem/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-xine-/}
PKGREVISION=	2

COMMENT+=	(using Xine)

CONFLICTS+=	totem-[0-9]*

CONFIGURE_ARGS+=	--enable-xine=yes

# needed for fake events to keep screensavers out, dubious
.include "../../x11/libXtst/buildlink3.mk"
# XVIDMODE is disabled in the source
#.include "../../x11/libXxf86vm/buildlink3.mk"

.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
