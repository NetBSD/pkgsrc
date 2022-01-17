# $NetBSD: Makefile,v 1.1 2022/01/17 13:23:17 nia Exp $

OBJS+=	xsol.o

LIBS+=	-lXm

all: xsol

xsol.o: xsol.c
	$(CC) $(CFLAGS) -c xsol.c

xsol: xsol.o
	$(CC) $(LDFLAGS) $(LIBS) -o xsol xsol.o
