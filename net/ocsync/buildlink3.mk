# $NetBSD: buildlink3.mk,v 1.16 2020/01/18 21:48:20 jperkin Exp $

BUILDLINK_TREE+=	ocsync

.if !defined(OCSYNC_BUILDLINK3_MK)
OCSYNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocsync+=	ocsync>=0.90.4
BUILDLINK_ABI_DEPENDS.ocsync?=	ocsync>=0.90.4nb16
BUILDLINK_PKGSRCDIR.ocsync?=	../../net/ocsync

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/iniparser/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.endif	# OCSYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocsync
