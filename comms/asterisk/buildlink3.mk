# $NetBSD: buildlink3.mk,v 1.2 2017/02/21 05:25:13 cherry Exp $

BUILDLINK_TREE+=	asterisk

.if !defined(ASTERISK_BUILDLINK3_MK)
ASTERISK_BUILDLINK3_MK:=

# Current user is comms/asterisk-chan-dongle, which is tied to v11.x
BUILDLINK_API_DEPENDS.asterisk+=	asterisk>=11.25.1nb1<12
BUILDLINK_PKGSRCDIR.asterisk?=	../../comms/asterisk
.endif	# ASTERISK_BUILDLINK3_MK

BUILDLINK_TREE+=	-asterisk
