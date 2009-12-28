# Makefile for f2c, a Fortran 77 to C converter

PROG=	f2c
SRCS=	main.c init.c gram.y lex.c proc.c equiv.c data.c format.c \
	expr.c exec.c intr.c io.c misc.c error.c mem.c names.c \
	output.c p1output.c pread.c put.c putpcc.c vax.c formatdata.c \
	parse_args.c niceprintf.c cds.c sysdep.c version.c $(MALLOC)

F2CSRCDIR=	.
.PATH:	$(F2CSRCDIR)

# To use the malloc whose source accompanies the f2c source,
# add malloc.c to the right-hand side of the "MALLOC =" line,
# so it becomes
#	MALLOC = malloc.c
# This gives faster execution on some systems, but some other
# systems do not tolerate replacement of the system's malloc.
MALLOC=		# empty

# In case yacc is broken, a correctly functioning gram.c is distributed
# (derived with a Unix variant of the yacc from plan9).

# There should be 4 shift/reduce conflicts:
gram.y:	gram.head gram.dcl gram.expr gram.exec gram.io tokdefs.h
	( sed "s/#define/%token/" < $(.ALLSRC:M*tokdefs.h) ; \
		cat $(.ALLSRC:M*gram.head) \
		    $(.ALLSRC:M*gram.dcl) \
		    $(.ALLSRC:M*gram.expr) \
		    $(.ALLSRC:M*gram.exec) \
		    $(.ALLSRC:M*gram.io) ) > $@
CLEANFILES+=	gram.y

DPADD=	defs.h ftypes.h defines.h machdefs.h sysdep.h

CPPFLAGS=	-I.		# generated files
CPPFLAGS+=	-I$(F2CSRCDIR)	# grammar

# tokdefs.h: tokens
# 	grep -n . <tokens | sed "s/\([^:]*\):\(.*\)/#define \2 \1/" >tokdefs.h

DPSRCS+=	sysdep.hd

# Handle obsolete systems like Solaris:
sysdep.hd:
	if $(CC) sysdeptest.c; then echo '/*OK*/' > sysdep.hd; \
	elif $(CC) -DNO_MKDTEMP sysdeptest.c; then echo '#define NO_MKDTEMP' > sysdep.hd; \
	else { echo '#define NO_MKDTEMP'; echo '#define NO_MKSTEMP'; } > sysdep.hd; fi
	rm -f a.out

CLEANFILES+=	sysdep.hd # sysdep.hd tokdefs.h f2c.t

.NOPATH:	f2c.1
f2c.1: f2c.1t
	sed -e 's!/usr!${PREFIX}!g' -e 's!lib/libc.a!usr/lib/libc.a!g' $> > $@

CLEANFILES+=	f2c.1

.include "bsd.prog.mk"
