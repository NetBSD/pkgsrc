# $NetBSD: Makefile,v 1.7 2004/04/19 18:17:04 drochner Exp $
#

.include "Makefile.common"

PKGREVISION=		1

.if ${MACHINE_ARCH} == "i386"
DEPENDS+=       	win32-codecs>=011227:../../multimedia/win32-codecs
PLIST_SRC=		${PKGDIR}/PLIST.i386
.endif
PLIST_SRC+=		${PKGDIR}/PLIST

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
