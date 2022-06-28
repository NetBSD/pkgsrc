# $NetBSD: buildlink3.mk,v 1.23 2022/06/28 11:34:35 wiz Exp $

BUILDLINK_TREE+=	squirrelmail

.if !defined(SQUIRRELMAIL_BUILDLINK3_MK)
SQUIRRELMAIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.squirrelmail+=	squirrelmail>=1.4.19
BUILDLINK_ABI_DEPENDS.squirrelmail?=	squirrelmail>=1.4.23pre14904nb2
BUILDLINK_PKGSRCDIR.squirrelmail?=	../../mail/squirrelmail
.endif # SQUIRRELMAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-squirrelmail
