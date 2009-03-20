# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:24:18 joerg Exp $

BUILDLINK_TREE+=	getopt

.if !defined(LIBGETOPT_BUILDLINK3_MK)
LIBGETOPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.getopt+=	libgetopt>=1.3
BUILDLINK_PKGSRCDIR.getopt?=	../../devel/libgetopt
.endif # LIBGETOPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-getopt
