# $NetBSD: Makefile,v 1.1.1.1 1999/12/23 01:27:35 abs Exp $
#

BASE_OS		= ${OS_VERSION:S/.//:C/\..*//}
.include "../../mk/bsd.prefs.mk"
#
.if (${MACHINE_ARCH} == "alpha")
.if (${BASE_OS} == 13)
DISTNAME=	${PKGNAME}.alpha-unknown-netbsd1.3.3
.else
DISTNAME=	${PKGNAME}.alpha-unknown-netbsd1.4
.endif
#
.elif (${MACHINE_ARCH} == "arm")
DISTNAME=	${PKGNAME}.arm-unknown-netbsd1.3I
#
.elif (${MACHINE_ARCH} == "i386")
.if (${BASE_OS} == 13)
DISTNAME=	${PKGNAME}.i386-unknown-netbsd1.3.2
.else
DISTNAME=	${PKGNAME}.i386-unknown-netbsd1.4
.endif
#
.elif (${MACHINE_ARCH} == "m68k")
DISTNAME=	${PKGNAME}.m68k-hp-netbsd1.3.3
#
.elif (${MACHINE_ARCH} == "sparc")
DISTNAME=	${PKGNAME}.sparc-sun-netbsd1.3.3
#
.endif
#
PKGNAME=	setiathome-1.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cdrom.com/pub/setiathome/ \
		ftp://alien.ssl.berkeley.edu/pub/ \
		ftp://setidata.ssl.berkeley.edu/pub/
EXTRACT_SUFX=	.tar

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://setiathome.ssl.berkeley.edu/

ONLY_FOR_PLATFORM= *-*-alpha *-*-arm *-*-i386 *-*-m68k *-*-sparc

DECOMPRESS_CMD=	${CAT}
NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/setiathome ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/man/cat1/setiathome.0

.include "../../mk/bsd.pkg.mk"
