# $NetBSD: gcc3.mk,v 1.12 2004/01/21 10:17:56 abs Exp $
#
# make configuration file for @DISTNAME@

USE_GCC3=	yes
CC=		@GCC_PREFIX@/bin/gcc
CPP=		@GCC_PREFIX@/bin/cpp
CXX=		@GCC_PREFIX@/bin/g++
F77=		@GCC_PREFIX@/bin/g77
PKG_FC=		@GCC_PREFIX@/bin/g77
