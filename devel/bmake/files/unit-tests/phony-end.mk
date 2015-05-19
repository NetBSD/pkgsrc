# $Id: phony-end.mk,v 1.1.1.1 2015/05/19 21:36:45 joerg Exp $

all ok also.ok bug phony:
	@echo '${.TARGET .PREFIX .IMPSRC:L:@v@$v="${$v}"@}'

.END:	ok also.ok bug

phony bug:	.PHONY
all: phony
