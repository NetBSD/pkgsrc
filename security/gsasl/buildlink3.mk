# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:39 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GSASL_BUILDLINK3_MK:=	${GSASL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gsasl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngsasl}
BUILDLINK_PACKAGES+=	gsasl

.if !empty(GSASL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gsasl+=	gsasl>=0.0.8
BUILDLINK_PKGSRCDIR.gsasl?=	../../security/gsasl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/libntlm/buildlink3.mk"
.include "../../security/gss/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

.endif	# GSASL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
