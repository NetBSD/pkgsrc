# $NetBSD: buildlink3.mk,v 1.14 2018/12/09 18:52:03 adam Exp $

BUILDLINK_TREE+=	mono

.if !defined(MONO_BUILDLINK3_MK)
MONO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mono+=		mono>=2.8<3
BUILDLINK_ABI_DEPENDS.mono+=		mono>=2.10.9nb26
BUILDLINK_PKGSRCDIR.mono?=		../../lang/mono2
ALL_ENV+=				MONO_SHARED_DIR=${WRKDIR}
BUILDLINK_CONTENTS_FILTER.mono+=	${EGREP} '(^include/|^lib/)'

.include "../../textproc/icu/buildlink3.mk"
.endif # MONO_BUILDLINK3_MK

BUILDLINK_TREE+=	-mono
