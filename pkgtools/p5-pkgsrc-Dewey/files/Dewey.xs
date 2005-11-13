#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include <dewey.h>

MODULE = pkgsrc::Dewey		PACKAGE = pkgsrc::Dewey		

int
dewey_match(pattern, package)
	const char *	pattern
	const char *	package
    PROTOTYPE: $;$
    OUTPUT:
	RETVAL

int
dewey_cmp(lhs, op, rhs)
	const char *	lhs
	const char *	op
	const char *	rhs
    PROTOTYPE: $;$;$
    INIT:
	int opi;
    CODE:
	if (dewey_mktest(&opi, op) < 0)
		RETVAL = -1;
	else
		RETVAL = dewey_cmp(lhs, opi, rhs);
    OUTPUT:
	RETVAL
