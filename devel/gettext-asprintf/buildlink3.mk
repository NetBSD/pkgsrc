# $NetBSD: buildlink3.mk,v 1.6 2011/04/12 17:41:28 adam Exp $

BUILDLINK_TREE+=	gettext-asprintf

.if !defined(GETTEXT_ASPRINTF_BUILDLINK3_MK)
GETTEXT_ASPRINTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gettext-asprintf+=	gettext-asprintf>=0.18
BUILDLINK_PKGSRCDIR.gettext-asprintf?=	../../devel/gettext-asprintf
.endif # GETTEXT_ASPRINTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-gettext-asprintf
