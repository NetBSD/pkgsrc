# $NetBSD: Makefile,v 1.63 2007/01/09 13:30:46 joerg Exp $
#

PKGREVISION=		6

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
.include "../../mk/bsd.pkg.mk"
