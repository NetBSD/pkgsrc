# $NetBSD: buildlink3.mk,v 1.6 2020/03/10 22:08:38 wiz Exp $

BUILDLINK_TREE+=	lilv

.if !defined(LILV_BUILDLINK3_MK)
LILV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lilv+=	lilv>=0.20.0
BUILDLINK_ABI_DEPENDS.lilv+=	lilv>=0.24.6nb2
BUILDLINK_PKGSRCDIR.lilv?=	../../audio/lilv

.include "../../audio/lv2/buildlink3.mk"
.include "../../converters/sratom/buildlink3.mk"
.include "../../textproc/sord/buildlink3.mk"
.include "../../textproc/serd/buildlink3.mk"
.endif	# LILV_BUILDLINK3_MK

BUILDLINK_TREE+=	-lilv
