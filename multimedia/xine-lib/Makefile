# $NetBSD: Makefile,v 1.13 2004/10/03 00:13:03 tv Exp $
#

.include "Makefile.common"

PKGREVISION=	2

.if ${MACHINE_ARCH} == "i386"
DEPENDS+=       	win32-codecs>=011227:../../multimedia/win32-codecs
PLIST_SUBST+=		I386=""
.else
PLIST_SUBST+=		I386="@comment "
.endif

BUILDLINK_DEPENDS.vcdimager+= vcdimager>=0.7.20nb1

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/xvidcore/buildlink3.mk"
.include "../../sysutils/vcdimager-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
