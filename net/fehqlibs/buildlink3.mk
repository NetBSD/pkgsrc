# $NetBSD: buildlink3.mk,v 1.6 2019/11/03 11:45:34 rillig Exp $

BUILDLINK_TREE+=	fehqlibs

.if !defined(FEHQLIBS_BUILDLINK3_MK)
FEHQLIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fehqlibs+=	fehqlibs>=0.9.12.10
BUILDLINK_PKGSRCDIR.fehqlibs?=		../../net/fehqlibs
BUILDLINK_INCDIRS.fehqlibs+=		include/qlibs
BUILDLINK_LIBDIRS.fehqlibs+=		lib/qlibs
LDFLAGS.SunOS+=				-lnsl -lsocket
.endif	# FEHQLIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-fehqlibs
