# $NetBSD: buildlink3.mk,v 1.9 2022/06/28 11:31:55 wiz Exp $

BUILDLINK_TREE+=	p5-B-Hooks-OP-Annotation

.if !defined(P5_B_HOOKS_OP_ANNOTATION_BUILDLINK3_MK)
P5_B_HOOKS_OP_ANNOTATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-B-Hooks-OP-Annotation+=	p5-B-Hooks-OP-Annotation>=0.43
BUILDLINK_ABI_DEPENDS.p5-B-Hooks-OP-Annotation?=	p5-B-Hooks-OP-Annotation>=0.44nb12
BUILDLINK_PKGSRCDIR.p5-B-Hooks-OP-Annotation?=		../../devel/p5-B-Hooks-OP-Annotation
BUILDLINK_INCDIRS.p5-B-Hooks-OP-Annotation?=		${PERL5_SUB_INSTALLVENDORARCH}/B/Hooks/OP/Annotation
BUILDLINK_CONTENTS_FILTER.p5-B-Hooks-OP-Annotation?=	${GREP} '${PERL5_SUB_INSTALLVENDORARCH}/B/Hooks/OP/Annotation'

.include "../../lang/perl5/buildlink3.mk"
.endif # P5_B_HOOKS_OP_ANNOTATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-B-Hooks-OP-Annotation
