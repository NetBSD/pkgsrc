# $NetBSD: buildlink3.mk,v 1.7 2004/10/03 00:13:24 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APR_BUILDLINK3_MK:=	${APR_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	apr
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Napr}
BUILDLINK_PACKAGES+=	apr

.if !empty(APR_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.apr+=	apr>=0.9.5.2.0.51nb1
BUILDLINK_RECOMMENDED.apr+=	apr>=0.9.5.2.0.52nb1
BUILDLINK_PKGSRCDIR.apr?=	../../devel/apr

BUILDLINK_FILES.apr+=	bin/apr-config
BUILDLINK_FILES.apr+=	bin/apu-config
BUILDLINK_FILES.apr+=	lib/*.exp
.endif	# APR_BUILDLINK3_MK

.if !empty(APR_USE_DB4:M[yY][eE][sS])
.  include "../../databases/db4/buildlink3.mk"
.elif !empty(APR_USE_OPENLDAP:M[Yy][Ee][Ss])
.  include "../../databases/openldap/buildlink3.mk"
.endif

.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
