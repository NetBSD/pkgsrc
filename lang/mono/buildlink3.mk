# $NetBSD: buildlink3.mk,v 1.66 2020/11/05 09:06:57 ryoon Exp $

BUILDLINK_TREE+=	mono

.if !defined(MONO_BUILDLINK3_MK)
MONO_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "NetBSD"
BUILDLINK_API_DEPENDS.mono+=	mono>=6
BUILDLINK_ABI_DEPENDS.mono?=	mono>=4.0.4.1nb22
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
