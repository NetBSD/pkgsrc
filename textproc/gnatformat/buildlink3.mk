# $NetBSD: buildlink3.mk,v 1.1 2025/09/07 07:51:55 dkazankov Exp $

BUILDLINK_TREE+=	gnatformat

.if !defined(GNATFORMAT_BUILDLINK3_MK)
GNATFORMAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnatformat+=	gnatformat>=25.0.0
BUILDLINK_PKGSRCDIR.gnatformat?=	../../textproc/gnatformat
BUILDLINK_DEPMETHOD.gnatformat?=	build

BUILDLINK_CONTENTS_FILTER.gnatformat=	\
	${EGREP} "bin/.*$$|include/.*$$|share/gpr/.*$$"

.endif

BUILDLINK_TREE+=	-gnatformat
