# $NetBSD: buildlink3.mk,v 1.8 2004/12/28 04:44:56 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXSLT_BUILDLINK3_MK:=	${LIBXSLT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxslt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxslt}
BUILDLINK_PACKAGES+=	libxslt

.if !empty(LIBXSLT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libxslt+=	libxslt>=1.1.8
BUILDLINK_RECOMMENDED.libxslt+=	libxslt>=1.1.10nb1
BUILDLINK_PKGSRCDIR.libxslt?=	../../textproc/libxslt
.endif	# LIBXSLT_BUILDLINK3_MK

PKG_OPTIONS.libxslt?=       ${PKG_DEFAULT_OPTIONS}

.if !empty(PKG_OPTIONS.libxslt:Mcrypto)
.  include "../../security/libgcrypt/buildlink3.mk"
.endif

.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
