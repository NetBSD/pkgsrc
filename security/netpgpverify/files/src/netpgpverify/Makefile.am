## $NetBSD: Makefile.am,v 1.1.1.1 2013/02/23 21:11:57 agc Exp $

AM_CFLAGS		= $(WARNCFLAGS)

bin_PROGRAMS		= netpgpverify

netpgpverify_SOURCES	= verify.c

netpgpverify_CPPFLAGS	= -I$(top_srcdir)/include

netpgpverify_LDADD	= ../lib/libnetpgp.la ../libmj/libmj.la

dist_man_MANS		= netpgpverify.1
