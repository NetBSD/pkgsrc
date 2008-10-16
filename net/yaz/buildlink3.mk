# $NetBSD: buildlink3.mk,v 1.11 2008/10/16 21:21:56 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
YAZ_BUILDLINK3_MK:=	${YAZ_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	yaz
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nyaz}
BUILDLINK_PACKAGES+=	yaz
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}yaz

.if !empty(YAZ_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.yaz+=	yaz>=2.0
BUILDLINK_ABI_DEPENDS.yaz+=	yaz>=3.0
BUILDLINK_PKGSRCDIR.yaz?=	../../net/yaz
.endif	# YAZ_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
