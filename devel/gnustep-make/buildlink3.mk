# $NetBSD: buildlink3.mk,v 1.2 2004/04/10 23:31:39 rh Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNUSTEP_MAKE_BUILDLINK3_MK:=	${GNUSTEP_MAKE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-make
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-make}
BUILDLINK_PACKAGES+=	gnustep-make

.if !empty(GNUSTEP_MAKE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnustep-make+=	gnustep-make>=1.9.1
BUILDLINK_PKGSRCDIR.gnustep-make?=	../../devel/gnustep-make

.include "../../devel/gnustep-make/gnustep.mk"

BUILDLINK_LIBDIRS.gnustep-make=	lib ${GNUSTEP_BLDIRS}
BUILDLINK_INCDIRS.gnustep-make=	include ${GNUSTEP_BIDIRS}

.endif	# GNUSTEP_MAKE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
