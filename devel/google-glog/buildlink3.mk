# $NetBSD: buildlink3.mk,v 1.1 2014/11/29 09:35:17 obache Exp $
#

BUILDLINK_TREE+=	google-glog

.if !defined(GOOGLE_GLOG_BUILDLINK3_MK)
GOOGLE_GLOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.google-glog+=	google-glog>=0.3.3
BUILDLINK_PKGSRCDIR.google-glog?=	../../devel/google-glog

.endif	# GOOGLE_GLOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-google-glog
