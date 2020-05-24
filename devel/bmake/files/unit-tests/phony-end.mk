# $Id: phony-end.mk,v 1.3 2020/05/24 11:09:44 nia Exp $

all ok also.ok bug phony:
	@echo '${.TARGET .PREFIX .IMPSRC:L:@v@$v="${$v}"@}'

.END:	ok also.ok bug

phony bug:	.PHONY
all: phony
