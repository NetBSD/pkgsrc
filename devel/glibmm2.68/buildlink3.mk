# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:31:44 wiz Exp $

BUILDLINK_TREE+=	glibmm2.68

.if !defined(GLIBMM2.68_BUILDLINK3_MK)
GLIBMM2.68_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glibmm2.68+=	glibmm2.68>=2.68.0
BUILDLINK_ABI_DEPENDS.glibmm2.68?=	glibmm2.68>=2.68.2nb1
BUILDLINK_PKGSRCDIR.glibmm2.68?=	../../devel/glibmm2.68

GCC_REQD+=	4.9

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++3/buildlink3.mk"
.endif	# GLIBMM2.68_BUILDLINK3_MK

BUILDLINK_TREE+=	-glibmm2.68
