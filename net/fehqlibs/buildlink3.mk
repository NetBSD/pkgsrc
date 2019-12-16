# $NetBSD: buildlink3.mk,v 1.7 2019/12/16 21:25:45 schmonz Exp $

BUILDLINK_TREE+=	fehqlibs

.if !defined(FEHQLIBS_BUILDLINK3_MK)
FEHQLIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fehqlibs+=	fehqlibs>=0.9.13
BUILDLINK_PKGSRCDIR.fehqlibs?=		../../net/fehqlibs
BUILDLINK_INCDIRS.fehqlibs+=		include/qlibs
BUILDLINK_LIBDIRS.fehqlibs+=		lib/qlibs
LDFLAGS.SunOS+=				-lnsl -lsocket
.endif	# FEHQLIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-fehqlibs
