# $NetBSD: doterror.mk,v 1.4 2024/07/15 09:10:20 jperkin Exp $


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
