# $NetBSD: Makefile,v 1.5 2002/09/09 18:28:26 wiz Exp $

DISTNAME=	ffcall-1.8d
PKGNAME=	ffcall-1.8.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/libs/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://clisp.cons.org/~haible/packages-ffcall.html
COMMENT=	ffcall - foreign function call libraries

# the file ${WRKDIR}/ffcall-1.8/avcall/avcall-${MACHINE_ARCH}.c needs to
# be added for additional port support.
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arm *-*-i386 *-*-m68k *-*-sparc *-*-sparc64

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

.include "../../mk/bsd.pkg.mk"
