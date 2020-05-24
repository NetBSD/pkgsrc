# $Id: qequals.mk,v 1.3 2020/05/24 11:09:44 nia Exp $

M= i386
V.i386= OK
V.$M ?= bug

all:
	@echo 'V.$M ?= ${V.$M}'
