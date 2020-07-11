# $NetBSD: Makefile,v 1.1 2020/07/11 13:58:11 nia Exp $

all: bit32.so

.c.o:
	$(CC) $(CFLAGS) -DLUA_COMPAT_BITLIB -fPIC -c $<

bit32.so: lbitlib.o
	$(CC) $(LDFLAGS) -shared -o $@ lbitlib.o
