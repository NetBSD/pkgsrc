#	$NetBSD: setup.mk,v 1.1 2010/01/17 01:41:33 dholland Exp $

KBD= unix.kbd

############################################################
# installation

DESTDIR?=# empty
PREFIX?=/usr/local

BINDIR?=$(PREFIX)/bin
MAN1DIR?=$(PREFIX)/man/man1
MAN5DIR?=$(PREFIX)/man/man5
SHAREDIR?=$(PREFIX)/share/tn3270

BINMODE?=755
MANMODE?=644
FILESMODE?=644

############################################################
# compile flags

CFLAGS+=-fstack-protector -Wstack-protector --param ssp-buffer-size=1
CFLAGS+=-Wall -Wstrict-prototypes -Wmissing-prototypes -Wpointer-arith
CFLAGS+=-Wsign-compare -Wno-traditional -Wno-pointer-sign
CFLAGS+=-DTERMCAP -DSRCRT -DKLUDGELINEMODE -DUSE_TERMIO -DTN3270 -Dunix

############################################################
# programs

CC?=cc
CFLAGS?=-O

MKDEP?=$(CC) -MM

INSTALL?=install

INSTALLDIR=$(INSTALL) -d
INSTALLBIN?=$(INSTALL) -c -m $(BINMODE)
INSTALLMAN?=$(INSTALL) -c -m $(MANMODE)
INSTALLFILE?=$(INSTALL) -c -m $(FILESMODE)

CFLAGS+=-DPATH_MAP3270=\"$(SHAREDIR)/map3270\"
