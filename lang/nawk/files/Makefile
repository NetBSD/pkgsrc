# $NetBSD: Makefile,v 1.4 2023/02/24 20:57:50 vins Exp $
#
# This file is copied from "makefile.orig" with the following
# modifications for pkgsrc:
#
#    * Some problematic comment lines and unnecessary make targets have
#      been stripped. 
#    * Use the supplied awkgram.tab.[ch] files instead of regenerating
#      them with yacc.
#    * Use the supplied proctab.c file instead of regenerating it
#      with maketab.
#

CFLAGS = -fsanitize=address -O1 -g -fno-omit-frame-pointer -fno-optimize-sibling-calls
CFLAGS = -g
CFLAGS =
CFLAGS = -O2

CC = gcc -g -Wall -pedantic -Wcast-qual
CC = cc

YACC = yacc -d -b awkgram
YACC = bison -d

OFILES = b.o main.o parse.o proctab.o tran.o lib.o run.o lex.o

SOURCE = awk.h awkgram.tab.c awkgram.tab.h proto.h awkgram.y lex.c b.c main.c \
	maketab.c parse.c lib.c run.c tran.c proctab.c

LISTING = awk.h proto.h awkgram.y lex.c b.c main.c maketab.c parse.c \
	lib.c run.c tran.c

SHIP = README FIXES $(SOURCE) awkgram.tab.[ch].bak makefile \
	awk.1

a.out:	 awkgram.tab.o $(OFILES)
	$(CC) $(CFLAGS) awkgram.tab.o $(OFILES) $(ALLOC)  -lm -o $@

maketab:	awkgram.tab.h maketab.c
	$(CC) $(CFLAGS) maketab.c -o maketab

clean:
	rm -f a.out *.o *.obj maketab maketab.exe *.bb *.bbg *.da *.gcov *.gcno *.gcda
