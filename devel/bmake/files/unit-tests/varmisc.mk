# $Id: varmisc.mk,v 1.1.1.1 2015/05/19 21:36:45 joerg Exp $
#
# Miscellaneous variable tests.

all: unmatched_var_paren

unmatched_var_paren:
	@echo ${foo::=foo-text}
