# $NetBSD: Makefile,v 1.4 2000/04/05 08:57:42 jdolecek Exp $
#

BASE_OS		= ${OS_VERSION:S/.//:C/\..*//}
PKGVERSION	= 1.2
.include "../../mk/bsd.prefs.mk"
#
.if ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "sparc"
PKGVERSION=	1.3
DISTNAME=	${PKGNAME}.sparc-sun-solaris2.6
#
.elif (${MACHINE_ARCH} == "alpha")
.if (${BASE_OS} == 13)
DISTNAME=	${PKGNAME}.alpha-unknown-netbsd1.3.3
.else
DISTNAME=	${PKGNAME}.alpha-unknown-netbsd1.4
.endif
#
.elif (${MACHINE_ARCH} == "i386")
.if (${BASE_OS} == 13)
DISTNAME=	${PKGNAME}.i386-unknown-netbsd1.3.2
.else
DISTNAME=	${PKGNAME}.i386-unknown-netbsd1.4
.endif
#
.elif (${MACHINE_ARCH} == "sparc")
DISTNAME=	${PKGNAME}.sparc-sun-netbsd1.3.3
#
.endif
#
PKGNAME=	setiathome-${PKGVERSION}
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cdrom.com/pub/setiathome/ \
		ftp://alien.ssl.berkeley.edu/pub/ \
		ftp://setidata.ssl.berkeley.edu/pub/
EXTRACT_SUFX=	.tar

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://setiathome.ssl.berkeley.edu/

ONLY_FOR_PLATFORM= *-*-alpha *-*-i386 *-*-sparc

DIST_SUBDIR=    setiathome
DECOMPRESS_CMD=	${CAT}
NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/setiathome ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/man/cat1/setiathome.0

.include "../../mk/bsd.pkg.mk"
