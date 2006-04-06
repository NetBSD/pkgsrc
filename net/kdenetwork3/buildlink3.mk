# $NetBSD: buildlink3.mk,v 1.8 2006/04/06 06:22:32 reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
KDENETWORK_BUILDLINK3_MK:=	${KDENETWORK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kdenetwork
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdenetwork}
BUILDLINK_PACKAGES+=	kdenetwork

.if !empty(KDENETWORK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.kdenetwork+=	kdenetwork>=3.5.0nb1
BUILDLINK_ABI_DEPENDS.kdenetwork?=	kdenetwork>=3.5.1nb1
BUILDLINK_PKGSRCDIR.kdenetwork?=	../../net/kdenetwork3
.endif	# KDENETWORK_BUILDLINK3_MK

.include "../../converters/uulib/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
