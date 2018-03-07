# $NetBSD: Makefile,v 1.80 2018/03/07 11:57:29 wiz Exp $

.include "Makefile.common"

PKGREVISION=	6

USE_TOOLS+=	msgfmt

CONFIGURE_ARGS+=	--disable-esd

PLIST_VARS+=		cdaudio

.if ${OPSYS} != "Darwin"
PLIST.cdaudio=		yes
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

REPLACE_SH=		xmms-config.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
