# $NetBSD: Makefile,v 1.16 2005/06/25 15:21:29 abs Exp $
#

DISTNAME=       ${PKGNAME_NOREV}
PKGNAME=	setiathome-3.08
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://alien.ssl.berkeley.edu/pub/ \
		ftp://setidata.ssl.berkeley.edu/pub/
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://setiathome.ssl.berkeley.edu/
COMMENT=	Search for Extraterrestrial Intelligence - at home

.include "../../mk/bsd.prefs.mk"

# Now rework distname based on OPSYS and MACHINE_ARCH. Does not handle
# rejecting older versions of operating systems
#
.if ${OPSYS} == "NetBSD"
#
DISTNAME=       ${PKGNAME_NOREV}.${MACHINE_ARCH}-unknown-netbsd1.6.1

.elif ${OPSYS} == "FreeBSD"
#
DISTNAME=	${PKGNAME_NOREV}.${MACHINE_ARCH}-unknown-freebsd4.0

.elif ${OPSYS} == "OpenBSD"
#
DISTNAME=       ${PKGNAME_NOREV}.${MACHINE_ARCH}-unknown-openbsd3.3

.elif ${OPSYS} == "SunOS"
#
.if ${MACHINE_ARCH} == "sparc"
DISTNAME=	${PKGNAME_NOREV}.sparc-sun-solaris2.6
.else
DISTNAME=	${PKGNAME_NOREV}.i386-pc-solaris2.6
.endif

.elif ${OPSYS} == "Linux"
#
.if ${MACHINE_ARCH} == "i386"
DISTNAME=	${PKGNAME_NOREV}.i686-pc-linux-gnu
.elif ${MACHINE_ARCH} == "x86_64"
DISTNAME=	${PKGNAME_NOREV}.x86_64-pc-linux-gnu
.endif

.endif

ONLY_FOR_PLATFORM=  NetBSD-*-sparc FreeBSD-*-i386 OpenBSD-*-alpha
ONLY_FOR_PLATFORM+= OpenBSD-*-i386 OpenBSD-*-macppc OpenBSD-*-sparc
ONLY_FOR_PLATFORM+= OpenBSD-*-sparc64 SunOS-*-sparc SunOS-*-i386 Linux-*-i386
ONLY_FOR_PLATFORM+= Linux-*-i386 Linux-*-x86_64

DIST_SUBDIR=    setiathome
DECOMPRESS_CMD=	${CAT}
NO_BUILD=	yes
USE_PKGINSTALL=	yes

RCD_SCRIPTS=	setiathome

INSTALLATION_DIRS=	bin man/cat1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/setiathome ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xsetiathome ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/man/cat1/setiathome.0
	${INSTALL_MAN} ${WRKSRC}/README.xsetiathome ${PREFIX}/man/cat1/xsetiathome.0

.include "../../mk/bsd.pkg.mk"
