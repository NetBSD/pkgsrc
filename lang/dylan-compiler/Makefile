# $NetBSD: Makefile,v 1.3 2002/01/17 08:26:41 agc Exp $
#

PKGNAME=	dylan-compiler-${DYLAN_VERSION}

PATCHDIR=	${.CURDIR}/../dylan-interpreter/patches
DISTINFO_FILE=	${.CURDIR}/../dylan-interpreter/distinfo

AUTOGEN_TARGET=	--enable-mindy-bootstrap

CONFLICTS=	dylan-interpreter-[0-9]*

pre-build:
	@${ECHO_MSG} "********************************** WARNING ***********************************"
	@${ECHO_MSG} "This package takes over 8 hours to build on an 800 MHz PIII with 128 MB memory"
	@${ECHO_MSG} "You could try the dylan interpreter, in ${.CURDIR}/../dylan-interpreter"
	@${ECHO_MSG} "********************************** WARNING ***********************************"

.include "../dylan-interpreter/Makefile.common"
