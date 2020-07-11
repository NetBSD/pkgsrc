# $NetBSD: Makefile,v 1.2 2020/07/11 14:20:05 nia Exp $

all: bit32.so

.c.o:
	$(CC) $(CFLAGS) -DLUA_COMPAT_BITLIB -fPIC -c $<

bit32.so: lbitlib.o
	$(CC) $(LDFLAGS) -z undefs -shared -o $@ lbitlib.o
