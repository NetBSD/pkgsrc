# $Id: qequals.mk,v 1.1.1.1 2015/05/19 21:36:45 joerg Exp $

M= i386
V.i386= OK
V.$M ?= bug

all:
	@echo 'V.$M ?= ${V.$M}'
