# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 08:37:35 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libid3tag.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBID3TAG_BUILDLINK3_MK:=	${LIBID3TAG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libid3tag
.endif

.if !empty(LIBID3TAG_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libid3tag
BUILDLINK_DEPENDS.libid3tag+=		libid3tag>=0.15.0b
BUILDLINK_PKGSRCDIR.libid3tag?=		../../audio/libid3tag

.include "../../devel/zlib/buildlink3.mk"

.endif # LIBID3TAG_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
