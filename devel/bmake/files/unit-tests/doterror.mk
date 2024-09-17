# $NetBSD: doterror.mk,v 1.5 2024/09/17 11:52:31 jperkin Exp $


.BEGIN:
	@echo At first, I am

.END:
	@echo not reached

.ERROR:
	@echo "$@: Looks like '${.ERROR_TARGET}' is upset."

all:	happy sad

happy:
	@echo $@

sad:
	@echo and now: $@; exit 1
