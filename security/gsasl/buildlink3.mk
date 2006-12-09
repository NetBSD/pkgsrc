# $NetBSD: buildlink3.mk,v 1.12 2006/12/09 14:06:13 obache Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GSASL_BUILDLINK3_MK:=	${GSASL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gsasl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngsasl}
BUILDLINK_PACKAGES+=	gsasl
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gsasl

.if !empty(GSASL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gsasl+=	gsasl>=0.2.15
BUILDLINK_PKGSRCDIR.gsasl?=	../../security/gsasl
.endif	# GSASL_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/libntlm/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
