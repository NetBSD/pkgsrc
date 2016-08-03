# $NetBSD: buildlink3.mk,v 1.24 2016/08/03 10:22:13 adam Exp $

BUILDLINK_TREE+=	eog

.if !defined(EOG_BUILDLINK3_MK)
EOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eog+=	eog>=2.30.2<3
BUILDLINK_ABI_DEPENDS.eog+=	eog>=2.32.1nb22
BUILDLINK_PKGSRCDIR.eog?=	../../graphics/eog

.include "../../devel/GConf/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# EOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-eog
