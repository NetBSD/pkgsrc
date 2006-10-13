# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/10/13 12:38:30 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSYLPH_BUILDLINK3_MK:=	${LIBSYLPH_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libsylph
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibsylph}
BUILDLINK_PACKAGES+=	libsylph
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libsylph

.if ${LIBSYLPH_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libsylph+=	libsylph>=0.3.0
BUILDLINK_PKGSRCDIR.libsylph?=	../../mail/libsylph
.endif	# LIBSYLPH_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
