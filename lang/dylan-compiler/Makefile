# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:24 rillig Exp $
#

PKGNAME=	dylan-compiler-${DYLAN_VERSION}

PATCHDIR=	${.CURDIR}/../../lang/dylan-interpreter/patches
DISTINFO_FILE=	${.CURDIR}/../../lang/dylan-interpreter/distinfo

CONFIGURE_ARGS+=	--enable-mindy-bootstrap

CONFLICTS=	dylan-interpreter-[0-9]*

pre-build:
	@${ECHO_MSG} "********************************** WARNING ***********************************"
	@${ECHO_MSG} "This package takes over 8 hours to build on an 800 MHz PIII with 128 MB memory"
	@${ECHO_MSG} "You could try the dylan interpreter, in ${.CURDIR}/../dylan-interpreter"
	@${ECHO_MSG} "********************************** WARNING ***********************************"

.include "../../lang/dylan-interpreter/Makefile.common"
