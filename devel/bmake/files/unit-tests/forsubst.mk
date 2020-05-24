# $Id: forsubst.mk,v 1.3 2020/05/24 11:09:44 nia Exp $

all: for-subst

here := ${.PARSEDIR}
# this should not run foul of the parser
.for file in ${.PARSEFILE}
for-subst:	  ${file:S;^;${here}/;g}
	@echo ".for with :S;... OK"
.endfor
