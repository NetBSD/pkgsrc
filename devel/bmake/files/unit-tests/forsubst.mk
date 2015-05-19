# $Id: forsubst.mk,v 1.1.1.1 2015/05/19 21:36:45 joerg Exp $

all: for-subst

here := ${.PARSEDIR}
# this should not run foul of the parser
.for file in ${.PARSEFILE}
for-subst:	  ${file:S;^;${here}/;g}
	@echo ".for with :S;... OK"
.endfor
