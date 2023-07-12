# $NetBSD: Makefile,v 1.2 2023/07/12 21:04:46 nia Exp $

CFLAGS+=	-std=c99

OBJS+=	main.o
OBJS+=	bcrypt.o
OBJS+=	blowfish.o
OBJS+=	ggentropy.o
OBJS+=	safebfuns.o

all: bcrypt.so

.c.o:
	$(CC) $(CFLAGS) -fPIC -c $<

bcrypt.so: $(OBJS)
	$(CC) $(LDFLAGS) -shared -o $@ $(OBJS)
