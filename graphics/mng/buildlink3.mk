# $NetBSD: buildlink3.mk,v 1.1 2004/01/24 00:59:26 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MNG_BUILDLINK3_MK:=	${MNG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mng
.endif

.if !empty(MNG_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		mng
BUILDLINK_DEPENDS.mng?=		mng>=1.0.0
BUILDLINK_PKGSRCDIR.mng?=	../../graphics/mng

.  include "../../devel/zlib/buildlink3.mk"
.  include "../../graphics/jpeg/buildlink3.mk"
.  include "../../graphics/lcms/buildlink3.mk"
.endif # MNG_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
