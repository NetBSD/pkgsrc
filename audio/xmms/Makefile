# $NetBSD: Makefile,v 1.66 2007/04/14 22:12:14 dillo Exp $
#

PKGREVISION=		8

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-esd

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	CDAUDIO="@comment "
_INSTALL_UNSTRIPPED=	yes
.else
PLIST_SUBST+=	CDAUDIO=""
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xf86vidmodeproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
