# $Id: doterror.mk,v 1.3 2020/05/24 11:09:44 nia Exp $


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

