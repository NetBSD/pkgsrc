# $NetBSD: buildlink3.mk,v 1.4 2006/02/05 23:10:02 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMATHEVAL_BUILDLINK3_MK:=	${LIBMATHEVAL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmatheval
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmatheval}
BUILDLINK_PACKAGES+=	libmatheval

.if !empty(LIBMATHEVAL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libmatheval+=	libmatheval>=1.1.0
BUILDLINK_RECOMMENDED.libmatheval+=	libmatheval>=1.1.1nb3
BUILDLINK_PKGSRCDIR.libmatheval?=	../../math/libmatheval
.endif	# LIBMATHEVAL_BUILDLINK3_MK

.include "../../devel/flex/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
