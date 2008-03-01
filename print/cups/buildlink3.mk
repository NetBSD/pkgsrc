# $NetBSD: buildlink3.mk,v 1.20 2008/03/01 14:14:20 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CUPS_BUILDLINK3_MK:=	${CUPS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cups
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncups}
BUILDLINK_PACKAGES+=	cups
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}cups

.if !empty(CUPS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.cups+=	cups>=1.1.19nb3
BUILDLINK_ABI_DEPENDS.cups+=	cups>=1.2.12nb3
BUILDLINK_PKGSRCDIR.cups?=	../../print/cups
.endif	# CUPS_BUILDLINK3_MK

pkgbase := cups
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.cups:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
.endif

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
