# $NetBSD: Makefile,v 1.10 2003/03/06 23:50:51 jmc Exp $

DISTNAME=	ffcall-1.8d
PKGNAME=	ffcall-1.8.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=libs/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.haible.de/bruno/packages-ffcall.html
COMMENT=	foreign function call libraries

# the file ${WRKDIR}/ffcall-1.8/avcall/avcall-${MACHINE_ARCH}.c needs to
# be added for additional port support.
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arm *-*-i386 *-*-m68k *-*-sparc *-*-sparc64 *-*-powerpc

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

post-patch:
	${CP} files/tramp-rs6000-netbsd.s ${WRKSRC}/callback/trampoline_r
	${CP} files/vacall-rs6000-netbsd.s ${WRKSRC}/callback/vacall_r

#
# Run the supplied tests to sanity check everything
#
post-build:
	cd ${WRKSRC} && ${MAKE} check

.include "../../mk/bsd.pkg.mk"
