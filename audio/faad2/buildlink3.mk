# $NetBSD: buildlink3.mk,v 1.1 2004/02/17 20:21:38 wiz Exp $
#
# This Makefile fragment is included by packages that use faad2.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FAAD2_BUILDLINK3_MK:=	${FAAD2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	faad2
.endif

.if !empty(FAAD2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			faad2
BUILDLINK_DEPENDS.faad2+=		faad2>=1.1
BUILDLINK_PKGSRCDIR.faad2?=		../../audio/faad2

.endif # FAAD2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
