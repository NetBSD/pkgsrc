# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:17:59 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SOUP_BUILDLINK3_MK:=	${SOUP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	soup
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsoup}
BUILDLINK_PACKAGES+=	soup

.if !empty(SOUP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.soup?=                soup>=0.7.10nb7
BUILDLINK_RECOMMENDED.soup?=            soup>=0.7.11nb1
BUILDLINK_PKGSRCDIR.soup?=	../../net/soup
.endif	# SOUP_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../devel/bonobo/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
