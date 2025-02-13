# $NetBSD: buildlink3.mk,v 1.2 2025/02/13 03:26:47 ryoon Exp $

BUILDLINK_TREE+=	pstoedit

.if !defined(PSTOEDIT_BUILDLINK3_MK)
PSTOEDIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pstoedit+=	pstoedit>=3.78nb26
BUILDLINK_PKGSRCDIR.pstoedit?=		../../graphics/pstoedit

BUILDLINK_INCDIRS.pstoedit+=		include/pstoedit
BUILDLINK_LIBDIRS.pstoedit+=		lib/pstoedit
BUILDLINK_FNAME_TRANSFORM.pstoedit+=	-e 's|lib/pstoedit/pkgconfig/|lib/pkgconfig/|'

.endif	# PSTOEDIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pstoedit
