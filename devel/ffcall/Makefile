# $NetBSD: Makefile,v 1.4 2001/02/16 14:38:23 wiz Exp $

DISTNAME=	ffcall-1.8
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.santafe.edu/pub/gnu/ \
		ftp://ftp.ilog.fr/pub/Users/haible/gnu/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://clisp.cons.org/~haible/packages-ffcall.html
COMMENT=	ffcall - foreign function call libraries

# the file ${WRKDIR}/ffcall-1.8/avcall/avcall-${MACHINE_ARCH}.c needs to
# be added for additional port support.
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arm *-*-i386 *-*-m68k *-*-sparc *-*-sparc64

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
