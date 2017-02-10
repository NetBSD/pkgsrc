# $NetBSD: buildlink3.mk,v 1.1 2017/02/10 11:01:48 cherry Exp $

BUILDLINK_TREE+=	asterisk

.if !defined(ASTERISK_BUILDLINK3_MK)
ASTERISK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.asterisk+=	asterisk>=11.25.1nb1
BUILDLINK_PKGSRCDIR.asterisk?=	../../comms/asterisk
.endif	# ASTERISK_BUILDLINK3_MK

BUILDLINK_TREE+=	-asterisk
