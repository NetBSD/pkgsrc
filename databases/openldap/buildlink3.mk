# $NetBSD: buildlink3.mk,v 1.9 2004/03/26 02:27:36 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OPENLDAP_BUILDLINK3_MK:=	${OPENLDAP_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openldap
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopenldap}
BUILDLINK_PACKAGES+=	openldap

.if !empty(OPENLDAP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.openldap+=	openldap>=2.1.22
BUILDLINK_RECOMMENDED.openldap?=	openldap>=2.1.25nb3
BUILDLINK_PKGSRCDIR.openldap?=	../../databases/openldap
.endif	# OPENLDAP_BUILDLINK3_MK

.if defined(USE_SASL2) && (${USE_SASL2} == "YES")
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.elif defined(USE_SASL) && (${USE_SASL} == "YES")
.  include "../../security/cyrus-sasl/buildlink3.mk"
.endif
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
