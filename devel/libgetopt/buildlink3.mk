# $NetBSD: buildlink3.mk,v 1.14 2014/01/01 02:48:31 ryoon Exp $

BUILDLINK_TREE+=	getopt

.if !defined(LIBGETOPT_BUILDLINK3_MK)
LIBGETOPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.getopt+=	libgetopt>=1.4.5
BUILDLINK_PKGSRCDIR.getopt?=	../../devel/libgetopt
.endif # LIBGETOPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-getopt
