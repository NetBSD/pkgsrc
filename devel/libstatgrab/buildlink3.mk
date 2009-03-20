# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:23 joerg Exp $

BUILDLINK_TREE+=	libstatgrab

.if !defined(LIBSTATGRAB_BUILDLINK3_MK)
LIBSTATGRAB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstatgrab+=	libstatgrab>=0.10
BUILDLINK_ABI_DEPENDS.libstatgrab+=	libstatgrab>=0.10.3nb1
BUILDLINK_PKGSRCDIR.libstatgrab?=	../../devel/libstatgrab
.endif # LIBSTATGRAB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstatgrab
