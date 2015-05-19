# $Id: qequals.mk,v 1.2 2015/05/19 22:01:19 joerg Exp $

M= i386
V.i386= OK
V.$M ?= bug

all:
	@echo 'V.$M ?= ${V.$M}'
