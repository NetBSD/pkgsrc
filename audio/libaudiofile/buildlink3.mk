# $NetBSD: buildlink3.mk,v 1.18 2012/01/12 16:34:28 adam Exp $

BUILDLINK_TREE+=	libaudiofile

.if !defined(LIBAUDIOFILE_BUILDLINK3_MK)
LIBAUDIOFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaudiofile+=	libaudiofile>=0.2.1
BUILDLINK_ABI_DEPENDS.libaudiofile+=	libaudiofile>=0.2.6nb1
BUILDLINK_PKGSRCDIR.libaudiofile?=	../../audio/libaudiofile

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif

.endif # LIBAUDIOFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaudiofile
