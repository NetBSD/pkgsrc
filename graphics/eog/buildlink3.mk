# $NetBSD: buildlink3.mk,v 1.21 2013/10/10 14:41:52 ryoon Exp $

BUILDLINK_TREE+=	eog

.if !defined(EOG_BUILDLINK3_MK)
EOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eog+=	eog>=2.30.2<3
BUILDLINK_ABI_DEPENDS.eog+=	eog>=2.32.1nb19
BUILDLINK_PKGSRCDIR.eog?=	../../graphics/eog

.include "../../devel/GConf/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# EOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-eog
