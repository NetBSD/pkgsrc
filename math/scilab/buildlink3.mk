# $NetBSD: buildlink3.mk,v 1.14 2012/05/07 01:53:46 dholland Exp $
#

BUILDLINK_TREE+=	scilab

.if !defined(SCILAB_BUILDLINK3_MK)
SCILAB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.scilab+=	scilab>=4.1
BUILDLINK_ABI_DEPENDS.scilab+=	scilab>=4.1
BUILDLINK_PKGSRCDIR.scilab?=	../../math/scilab

BUILDLINK_FILES.scilab+=	lib/scilab-${SCIVERSION}/Version.incl

SCI=	${BUILDLINK_DIR}/lib/scilab-4.1
CONFIGURE_ENV+=	SCI=${SCI:Q}
MAKE_ENV+=	SCI=${SCI:Q}

SCIVERSION=	4.1
.endif # SCILAB_BUILDLINK3_MK

BUILDLINK_TREE+=	-scilab
