# $NetBSD: phony-end.mk,v 1.5 2024/09/17 11:52:33 jperkin Exp $

all ok also.ok bug phony:
	@echo '${.TARGET .PREFIX .IMPSRC:L:@v@$v="${$v}"@}'

.END:	ok also.ok bug

phony bug:	.PHONY
all: phony
