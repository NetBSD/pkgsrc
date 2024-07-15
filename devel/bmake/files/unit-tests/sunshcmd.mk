# $NetBSD: sunshcmd.mk,v 1.2 2024/07/15 09:10:27 jperkin Exp $

BYECMD=		  echo bye
LATERCMD=	  echo later
TEST1 :sh	= echo hello
TEST2 :sh	= ${BYECMD}
TEST3=		  ${LATERCMD:sh}

all:
	@echo "TEST1=${TEST1}"
	@echo "TEST2=${TEST2}"
	@echo "TEST3=${TEST3}"
