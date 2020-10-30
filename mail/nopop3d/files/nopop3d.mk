# $NetBSD: nopop3d.mk,v 1.1 2020/10/30 10:19:22 schmonz Exp $

nopop3d: \
load nopop3d.o commands.o case.a timeoutread.o timeoutwrite.o \
sig.a stralloc.a alloc.a substdio.a error.a str.a \
socket.lib
	./load nopop3d commands.o case.a timeoutread.o timeoutwrite.o \
	sig.a stralloc.a alloc.a substdio.a error.a str.a \
	`cat socket.lib`

nopop3d.o: \
compile nopop3d.c \
commands.h sig.h substdio.h readwrite.h timeoutread.h timeoutwrite.h
	./compile nopop3d.c
