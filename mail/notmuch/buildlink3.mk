# $NetBSD: buildlink3.mk,v 1.10 2021/12/08 16:02:20 adam Exp $

BUILDLINK_TREE+=	notmuch

.if !defined(NOTMUCH_BUILDLINK3_MK)
NOTMUCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.notmuch+=	notmuch>=0.16
BUILDLINK_ABI_DEPENDS.notmuch+=	notmuch>=0.34.1
BUILDLINK_PKGSRCDIR.notmuch?=	../../mail/notmuch

.include "../../mail/gmime3/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.endif	# NOTMUCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-notmuch
