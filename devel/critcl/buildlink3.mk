# $NetBSD: buildlink3.mk,v 1.1 2025/02/26 03:35:14 scole Exp $

BUILDLINK_TREE+=	critcl

.if !defined(CRITCL_BUILDLINK3_MK)
CRITCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.critcl+=	critcl>=3.3.1
BUILDLINK_ABI_DEPENDS.critcl?=	critcl>=3.3.1
BUILDLINK_PKGSRCDIR.critcl?=	../../devel/critcl
BUILDLINK_DEPMETHOD.critcl=	full

BUILDLINK_FILES.critcl+=	bin/critcl

.include "../../lang/tcl/buildlink3.mk"
.endif # CRITCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-critcl
