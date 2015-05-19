# $Id: varmisc.mk,v 1.2 2015/05/19 22:01:19 joerg Exp $
#
# Miscellaneous variable tests.

all: unmatched_var_paren

unmatched_var_paren:
	@echo ${foo::=foo-text}
