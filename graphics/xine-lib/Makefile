# $NetBSD: Makefile,v 1.18 2004/01/26 12:31:03 jmmv Exp $
#

.include "Makefile.common"

PKGREVISION=		3

.if ${MACHINE_ARCH} == "i386"
DEPENDS+=       	win32-codecs>=011227:../../multimedia/win32-codecs
PLIST_SRC=		${PKGDIR}/PLIST.i386
.endif
PLIST_SRC+=		${PKGDIR}/PLIST

.include "../../audio/flac/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/aalib/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xvidcore/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
