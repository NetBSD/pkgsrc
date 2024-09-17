# $NetBSD: ternary.mk,v 1.3 2024/09/17 11:52:33 jperkin Exp $

all:
	@for x in "" A= A=42; do ${.MAKE} -f ${MAKEFILE} show $$x; done

show:
	@echo "The answer is ${A:?known:unknown}"
	@echo "The answer is ${A:?$A:unknown}"
	@echo "The answer is ${empty(A):?empty:$A}"
