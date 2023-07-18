# $NetBSD: buildlink3.mk,v 1.10 2023/07/18 18:44:16 nia Exp $

BUILDLINK_TREE+=	polkit

.if !defined(POLKIT_BUILDLINK3_MK)
POLKIT_BUILDLINK3_MK:=

USE_CXX_FEATURES+=		c++17

BUILDLINK_API_DEPENDS.polkit+=	polkit>=0.103
BUILDLINK_ABI_DEPENDS.polkit?=	polkit>=0.120nb4
BUILDLINK_PKGSRCDIR.polkit?=	../../security/polkit

#.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
#.include "../../textproc/expat/buildlink3.mk"
.endif	# POLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-polkit
