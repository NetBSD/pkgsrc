# $NetBSD: ternary.mk,v 1.2 2024/07/15 09:10:27 jperkin Exp $

all:
	@for x in "" A= A=42; do ${.MAKE} -f ${MAKEFILE} show $$x; done

show:
	@echo "The answer is ${A:?known:unknown}"
	@echo "The answer is ${A:?$A:unknown}"
	@echo "The answer is ${empty(A):?empty:$A}"
