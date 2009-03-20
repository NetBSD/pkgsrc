# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:23:56 joerg Exp $

BUILDLINK_TREE+=	libofa

.if !defined(LIBOFA_BUILDLINK3_MK)
LIBOFA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libofa+=	libofa>=0.9.3
BUILDLINK_PKGSRCDIR.libofa?=	../../audio/libofa

.include "../../math/fftw/buildlink3.mk"
.endif # LIBOFA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libofa
