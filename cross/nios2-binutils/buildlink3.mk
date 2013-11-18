# $NetBSD: buildlink3.mk,v 1.1 2013/11/18 06:41:27 mef Exp $

BUILDLINK_TREE+=	nios2-binutils

.if !defined(NIOS2_BINUTILS_BUILDLINK3_MK)
NIOS2_BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nios2-binutils+=		nios2-binutils>=2.20
BUILDLINK_PKGSRCDIR.nios2-binutils?=		../../cross/nios2-binutils
BUILDLINK_FNAME_TRANSFORM.nios2-binutils+=	-e "s,${NIOS2_TARGET}/lib,lib/,g"
#BUILDLINK_CONTENTS_FILTER.nios2-binutils=	${EGREP} '.*'
BUILDLINK_CONTENTS_FILTER.nios2-binutils=	${GREP} '${CROSSBASE}'

.endif # NIOS2-BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nios2-binutils
