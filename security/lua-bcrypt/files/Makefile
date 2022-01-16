# $NetBSD: Makefile,v 1.1 2022/01/16 13:41:13 nia Exp $

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
