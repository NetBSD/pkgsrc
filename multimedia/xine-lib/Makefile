# $NetBSD: Makefile,v 1.3 2004/02/27 13:54:49 jmmv Exp $
#

.include "Makefile.common"

PKGREVISION=		3

.if ${MACHINE_ARCH} == "i386"
DEPENDS+=       	win32-codecs>=011227:../../multimedia/win32-codecs
PLIST_SRC=		${PKGDIR}/PLIST.i386
.endif
PLIST_SRC+=		${PKGDIR}/PLIST

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/xvidcore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
