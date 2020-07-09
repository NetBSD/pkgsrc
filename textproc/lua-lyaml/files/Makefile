# $NetBSD: Makefile,v 1.1 2020/07/09 21:30:17 nia Exp $

CFLAGS+=	-fPIC -Wall
CFLAGS+=	-DVERSION=\"$(PKGVERSION)\"
LDFLAGS+=	-shared -lyaml

OBJS+=		 emitter.o parser.o scanner.o yaml.o

all: yaml.so

.c.o:
	$(CC) $(CFLAGS) -c $<

yaml.so: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)
