# $NetBSD: buildlink3.mk,v 1.1 2025/09/07 08:08:51 dkazankov Exp $

BUILDLINK_TREE+=	gnatdoc

.if !defined(GNATDOC_BUILDLINK3_MK)
GNATDOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnatdoc+=	gnatdoc>=25.0.0
BUILDLINK_PKGSRCDIR.gnatdoc?=	../../textproc/gnatdoc
BUILDLINK_DEPMETHOD.gnatdoc?=	build

BUILDLINK_CONTENTS_FILTER.gnatdoc=	\
	${EGREP} "bin/.*$$|include/.*$$|share/gpr/.*$$"

.endif

BUILDLINK_TREE+=	-gnatdoc
