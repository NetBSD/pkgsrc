# $NetBSD: buildlink3.mk,v 1.1 2004/04/20 13:02:56 markd Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
KDENETWORK_BUILDLINK3_MK:=	${KDENETWORK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kdenetwork
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdenetwork}
BUILDLINK_PACKAGES+=	kdenetwork

.if !empty(KDENETWORK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.kdenetwork+=	kdenetwork>=3.2.0
BUILDLINK_RECOMMENDED.kdenetwork?=	kdenetwork>=3.2.2
BUILDLINK_PKGSRCDIR.kdenetwork?=	../../net/kdenetwork3
.endif	# KDENETWORK_BUILDLINK3_MK

.include "../../converters/uulib/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
