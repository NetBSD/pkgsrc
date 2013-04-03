# $NetBSD: buildlink3.mk,v 1.1 2013/04/03 12:23:51 markd Exp $

BUILDLINK_TREE+=	libkcompactdisc

.if !defined(LIBKCOMPACTDISC_BUILDLINK3_MK)
LIBKCOMPACTDISC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkcompactdisc+=	libkcompactdisc>=4.10.2
BUILDLINK_PKGSRCDIR.libkcompactdisc?=	../../multimedia/libkcompactdisc

.endif	# LIBKCOMPACTDISC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkcompactdisc
