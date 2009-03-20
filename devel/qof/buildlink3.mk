# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:28 joerg Exp $

BUILDLINK_TREE+=	qof

.if !defined(QOF_BUILDLINK3_MK)
QOF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qof+=	qof>=0.7.5
BUILDLINK_PKGSRCDIR.qof?=	../../devel/qof

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # QOF_BUILDLINK3_MK

BUILDLINK_TREE+=	-qof
