# $NetBSD: buildlink3.mk,v 1.4 2006/01/21 20:42:39 tron Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RPM_BUILDLINK3_MK:=	${RPM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	rpm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nrpm}
BUILDLINK_PACKAGES+=	rpm

.if !empty(RPM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.rpm+=	rpm>=2.5.4nb4
BUILDLINK_PKGSRCDIR.rpm?=	../../misc/rpm
BUILDLINK_DEPMETHOD.rpm?=	build

BUILDLINK_CPPFLAGS.rpm= -I${BUILDLINK_PREFIX.rpm}/include/rpm
.endif	# RPM_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
