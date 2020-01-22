# $NetBSD: buildlink3.mk,v 1.63 2020/01/22 21:31:00 nia Exp $

BUILDLINK_TREE+=	mono

.if !defined(MONO_BUILDLINK3_MK)
MONO_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "NetBSD"
BUILDLINK_API_DEPENDS.mono+=	mono>=6
BUILDLINK_ABI_DEPENDS.mono?=	mono>=6
BUILDLINK_PKGSRCDIR.mono?=	../../lang/mono6
.else
BUILDLINK_API_DEPENDS.mono+=	mono>=4
BUILDLINK_ABI_DEPENDS.mono?=	mono>=4.0.4.1nb15
BUILDLINK_PKGSRCDIR.mono?=	../../lang/mono
.endif

ALL_ENV+=			MONO_SHARED_DIR=${WRKDIR}
BUILDLINK_CONTENTS_FILTER.mono=	${EGREP} '(^include/|^lib/)'

.include "../../textproc/icu/buildlink3.mk"
.endif # MONO_BUILDLINK3_MK

BUILDLINK_TREE+=	-mono
