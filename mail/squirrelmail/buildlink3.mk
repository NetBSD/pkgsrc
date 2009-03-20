# $NetBSD: buildlink3.mk,v 1.21 2009/03/20 19:24:56 joerg Exp $

BUILDLINK_TREE+=	squirrelmail

.if !defined(SQUIRRELMAIL_BUILDLINK3_MK)
SQUIRRELMAIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.squirrelmail+=	squirrelmail>=1.4.17
BUILDLINK_PKGSRCDIR.squirrelmail?=	../../mail/squirrelmail
.endif # SQUIRRELMAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-squirrelmail
