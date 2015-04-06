# $NetBSD: buildlink3.mk,v 1.51 2015/04/06 08:17:15 adam Exp $

BUILDLINK_TREE+=	mono

.if !defined(MONO_BUILDLINK3_MK)
MONO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mono+=	mono>=3
BUILDLINK_ABI_DEPENDS.mono?=	mono>=3.10.0nb1
BUILDLINK_PKGSRCDIR.mono?=	../../lang/mono
ALL_ENV+=			MONO_SHARED_DIR=${WRKDIR:Q}
BUILDLINK_CONTENTS_FILTER.mono=	${EGREP} '(^include/|^lib/)'

.include "../../textproc/icu/buildlink3.mk"
.endif # MONO_BUILDLINK3_MK

BUILDLINK_TREE+=	-mono
