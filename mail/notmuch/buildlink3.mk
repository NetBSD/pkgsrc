# $NetBSD: buildlink3.mk,v 1.1 2014/01/09 12:15:23 wiz Exp $

BUILDLINK_TREE+=	notmuch

.if !defined(NOTMUCH_BUILDLINK3_MK)
NOTMUCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.notmuch+=	notmuch>=0.16
BUILDLINK_PKGSRCDIR.notmuch?=	../../mail/notmuch

.include "../../mail/gmime24/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.endif	# NOTMUCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-notmuch
