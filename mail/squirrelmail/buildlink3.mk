# $NetBSD: buildlink3.mk,v 1.22 2009/05/22 07:05:14 martti Exp $

BUILDLINK_TREE+=	squirrelmail

.if !defined(SQUIRRELMAIL_BUILDLINK3_MK)
SQUIRRELMAIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.squirrelmail+=	squirrelmail>=1.4.19
BUILDLINK_PKGSRCDIR.squirrelmail?=	../../mail/squirrelmail
.endif # SQUIRRELMAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-squirrelmail
