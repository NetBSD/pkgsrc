#	$NetBSD: Makefile,v 1.2 2010/01/17 01:41:34 dholland Exp $

TOP=../..
include $(TOP)/mk/setup.mk

PROG=mkmake
SRCS=mkmake.y

CFLAGS+=-I../../api
CFLAGS+=-DHOST_TOOL

# should be hostprog.mk for crosscompiling (FUTURE)
include $(TOP)/mk/prog.mk
