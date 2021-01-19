# $NetBSD: buildlink3.mk,v 1.5 2021/01/19 22:36:19 nia Exp $
#

BUILDLINK_TREE+=	polkit

.if !defined(POLKIT_BUILDLINK3_MK)
# configure: error: *** A compiler with support for C++17 language features is required.
GCC_REQD+=	7

POLKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polkit+=	polkit>=0.103
BUILDLINK_ABI_DEPENDS.polkit?=	polkit>=0.118nb1
BUILDLINK_PKGSRCDIR.polkit?=	../../security/polkit

#.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
#.include "../../textproc/expat/buildlink3.mk"
.endif	# POLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-polkit
