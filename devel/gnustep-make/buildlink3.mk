# $NetBSD: buildlink3.mk,v 1.21 2025/02/20 14:34:52 manu Exp $

BUILDLINK_TREE+=	gnustep-make

.if !defined(GNUSTEP_MAKE_BUILDLINK3_MK)
GNUSTEP_MAKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-make+=	gnustep-make>=2.9.3
BUILDLINK_ABI_DEPENDS.gnustep-make+=	gnustep-make>=2.9.3
BUILDLINK_PKGSRCDIR.gnustep-make?=	../../devel/gnustep-make

.include "../../devel/gnustep-make/gnustep.mk"

BUILDLINK_LIBDIRS.gnustep-make=	lib ${GNUSTEP_BLDIRS}
BUILDLINK_INCDIRS.gnustep-make=	include ${GNUSTEP_BIDIRS}
.endif # GNUSTEP_MAKE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-make
