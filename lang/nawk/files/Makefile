# $NetBSD: Makefile,v 1.2 2007/05/07 22:39:07 rillig Exp $
#
# This file is copied from "makefile" with the following modifications
# for pkgsrc:
#
#    * Some problematic comments lines were stripped.
#    * Use the supplied ytab.[ch] files instead of regenerating them
#      with yacc.
#    * Use the supplied proctab.c file instead of regenerating it
#      with maketab.
#

CFLAGS = -g
CFLAGS = -O2
CFLAGS =

CC = gcc -Wall -g -Wwrite-strings
CC = gcc -fprofile-arcs -ftest-coverage
CC = gcc -Wall -g
CC = cc

YACC = bison -y
YACC = yacc
YFLAGS = -d

OFILES = b.o main.o parse.o proctab.o tran.o lib.o run.o lex.o

SOURCE = awk.h ytab.c ytab.h proto.h awkgram.y lex.c b.c main.c \
	maketab.c parse.c lib.c run.c tran.c proctab.c missing95.c

LISTING = awk.h proto.h awkgram.y lex.c b.c main.c maketab.c parse.c \
	lib.c run.c tran.c missing95.c

SHIP = README FIXES $(SOURCE) ytab[ch].bak makefile makefile.win \
	vcvars32.bat buildwin.bat mac.code awk.1

a.out:	ytab.o $(OFILES)
	$(CC) $(CFLAGS) ytab.o $(OFILES) $(ALLOC)  -lm -o $@

clean:
	rm -f a.out *.o *.obj maketab maketab.exe *.bb *.bbg *.da *.gcov # proctab.c
