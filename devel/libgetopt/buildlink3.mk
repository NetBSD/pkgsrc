# $NetBSD: buildlink3.mk,v 1.15 2014/09/11 21:48:34 jperkin Exp $

BUILDLINK_TREE+=	getopt

.if !defined(LIBGETOPT_BUILDLINK3_MK)
LIBGETOPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.getopt+=	libgetopt>=1.4.6
BUILDLINK_PKGSRCDIR.getopt?=	../../devel/libgetopt
.endif # LIBGETOPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-getopt
