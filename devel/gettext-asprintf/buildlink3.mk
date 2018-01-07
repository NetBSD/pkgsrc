# $NetBSD: buildlink3.mk,v 1.7 2018/01/07 13:04:01 rillig Exp $

BUILDLINK_TREE+=	gettext-asprintf

.if !defined(GETTEXT_ASPRINTF_BUILDLINK3_MK)
GETTEXT_ASPRINTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gettext-asprintf+=	gettext-asprintf>=0.18
BUILDLINK_PKGSRCDIR.gettext-asprintf?=		../../devel/gettext-asprintf
.endif # GETTEXT_ASPRINTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-gettext-asprintf
