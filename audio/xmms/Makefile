# $NetBSD: Makefile,v 1.77 2012/10/02 23:48:14 asau Exp $
#

.include "Makefile.common"

PKGREVISION=	4

USE_TOOLS+=	msgfmt

CONFIGURE_ARGS+=	--disable-esd

PLIST_VARS+=		cdaudio

.if ${OPSYS} == "Darwin"
_INSTALL_UNSTRIPPED=	yes
.else
PLIST.cdaudio=		yes
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

REPLACE_SH=		xmms-config.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xf86vidmodeproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
