# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 01:23:36 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libglade2.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGLADE2_BUILDLINK3_MK:=	${LIBGLADE2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libglade2
.endif

.if !empty(LIBGLADE2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libglade2
BUILDLINK_DEPENDS.libglade2+=		libglade2>=2.0.1nb13
BUILDLINK_PKGSRCDIR.libglade2?=		../../devel/libglade2

BUILDLINK_CPPFLAGS.libglade2= \
	-I${BUILDLINK_PREFIX.libglade2}/include/libglade-2.0

CPPFLAGS+=	${BUILDLINK_CPPFLAGS.libglade2}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # LIBGLADE2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
