# $NetBSD: buildlink3.mk,v 1.52 2015/05/21 20:03:23 kefren Exp $

BUILDLINK_TREE+=	mono

.if !defined(MONO_BUILDLINK3_MK)
MONO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mono+=	mono>=4
BUILDLINK_ABI_DEPENDS.mono?=	mono>=4.0.1
BUILDLINK_PKGSRCDIR.mono?=	../../lang/mono
ALL_ENV+=			MONO_SHARED_DIR=${WRKDIR:Q}
BUILDLINK_CONTENTS_FILTER.mono=	${EGREP} '(^include/|^lib/)'

.include "../../textproc/icu/buildlink3.mk"
.endif # MONO_BUILDLINK3_MK

BUILDLINK_TREE+=	-mono
