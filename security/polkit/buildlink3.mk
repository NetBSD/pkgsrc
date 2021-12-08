# $NetBSD: buildlink3.mk,v 1.7 2021/12/08 16:02:35 adam Exp $

BUILDLINK_TREE+=	polkit

.if !defined(POLKIT_BUILDLINK3_MK)
POLKIT_BUILDLINK3_MK:=

# configure: error: *** A compiler with support for C++17 language features is required.
GCC_REQD+=	7

BUILDLINK_API_DEPENDS.polkit+=	polkit>=0.103
BUILDLINK_ABI_DEPENDS.polkit?=	polkit>=0.120
BUILDLINK_PKGSRCDIR.polkit?=	../../security/polkit

#.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
#.include "../../textproc/expat/buildlink3.mk"
.endif	# POLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-polkit
