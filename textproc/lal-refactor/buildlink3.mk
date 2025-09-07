# $NetBSD: buildlink3.mk,v 1.1 2025/09/07 07:36:24 dkazankov Exp $

BUILDLINK_TREE+=	lal-refactor

.if !defined(LAL_REFACTOR_BUILDLINK3_MK)
LAL_REFACTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lal-refactor+=	lal-refactor>=25.0.0
BUILDLINK_PKGSRCDIR.lal-refactor?=	../../textproc/lal-refactor
BUILDLINK_DEPMETHOD.lal-refactor?=	build

BUILDLINK_CONTENTS_FILTER.lal-refactor=	\
	${EGREP} "bin/.*$$|include/.*$$|share/gpr/.*$$"

.endif

BUILDLINK_TREE+=	-lal-refactor
