# $NetBSD: buildlink3.mk,v 1.3 2006/02/05 23:08:54 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SWIG_BUILDLINK3_MK:=	${SWIG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	swig
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nswig}
BUILDLINK_PACKAGES+=	swig

.if !empty(SWIG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.swig+=	swig>=1.3.24
BUILDLINK_RECOMMENDED.swig?=	swig>=1.3.24nb2
BUILDLINK_PKGSRCDIR.swig?=	../../devel/swig
# only contains a static library
BUILDLINK_DEPMETHOD.swig?=	build

BUILDLINK_FILES.swig+=		share/swig/1.3/* share/swig/1.3/*/*
.endif	# SWIG_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
