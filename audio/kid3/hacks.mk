# $NetBSD: hacks.mk,v 1.2 2019/11/02 21:09:14 rillig Exp $

# linking -lQt5Widgets on NetBSD with gcc produces
# ld: BFD (NetBSD Binutils nb1) 2.27 assertion fail
# /usr/src/external/gpl3/binutils/lib/libbfd/../../dist/bfd/elflink.c:2694
# unless -lexecinfo preceeds -lQt5Widgets
BUILDLINK_TRANSFORM.NetBSD+=	l:Qt5Widgets:execinfo:Qt5Widgets
