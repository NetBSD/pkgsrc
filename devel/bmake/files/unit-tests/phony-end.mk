# $NetBSD: phony-end.mk,v 1.4 2024/07/15 09:10:25 jperkin Exp $

all ok also.ok bug phony:
	@echo '${.TARGET .PREFIX .IMPSRC:L:@v@$v="${$v}"@}'

.END:	ok also.ok bug

phony bug:	.PHONY
all: phony
