# $NetBSD: Makefile,v 1.74 2012/01/13 10:54:49 obache Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=	3

USE_TOOLS+=	msgfmt

CONFIGURE_ARGS+=	--disable-esd

PLIST_VARS+=		cdaudio

.if ${OPSYS} == "Darwin"
_INSTALL_UNSTRIPPED=	yes
.else
PLIST.cdaudio=		yes
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xf86vidmodeproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
