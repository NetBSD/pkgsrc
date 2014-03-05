# $NetBSD: Makefile,v 1.1.1.1 2014/03/05 05:09:44 agc Exp $

.include <bsd.own.mk>

PROG=m
SRCS= blake2.c crc32c.c keccak.c main.c md5c.c multigest.c rmd160.c sha1.c sha2.c tiger.c whirlpool.c
CPPFLAGS+=-I.

CPPFLAGS+=-g -O0
LDFLAGS+=-g -O0

WARNS=6
MAN=multigest.1

.include <bsd.prog.mk>

t: ${PROG}
	./${PROG} -o 20.out -a blake2,crc32c,md5,rmd160,sha1,sha256,sha3-224,sha3-256,sha3-384,sha3-512,sha512,size,tiger2,tiger,whirlpool -r ${.CURDIR}/../bin/2.in
	diff 20.expected 20.out
	rm -f 20.out
