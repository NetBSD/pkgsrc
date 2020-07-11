# $NetBSD: Makefile,v 1.3 2020/07/11 14:49:23 nia Exp $

all: bit32.so

.c.o:
	$(CC) $(CFLAGS) -DLUA_COMPAT_BITLIB -fPIC -c $<

bit32.so: lbitlib.o
	$(CC) $(LDFLAGS) -shared -o $@ lbitlib.o
