# $NetBSD: buildlink3.mk,v 1.3 2020/03/08 16:48:08 wiz Exp $
#

BUILDLINK_TREE+=	polkit

.if !defined(POLKIT_BUILDLINK3_MK)
POLKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polkit+=	polkit>=0.103
BUILDLINK_ABI_DEPENDS.polkit?=	polkit>=0.115nb4
BUILDLINK_PKGSRCDIR.polkit?=	../../security/polkit

#.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
#.include "../../textproc/expat/buildlink3.mk"
.endif	# POLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-polkit
