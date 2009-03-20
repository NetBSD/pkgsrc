# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:23:55 joerg Exp $

BUILDLINK_TREE+=	libmpcdec

.if !defined(LIBMPCDEC_BUILDLINK3_MK)
LIBMPCDEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmpcdec+=	libmpcdec>=1.2.4
BUILDLINK_ABI_DEPENDS.libmpcdec+=	libmpcdec>=1.2.6
BUILDLINK_PKGSRCDIR.libmpcdec?=	../../audio/libmpcdec
.endif # LIBMPCDEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmpcdec
