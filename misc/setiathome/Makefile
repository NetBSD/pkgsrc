# $NetBSD: Makefile,v 1.8 2001/10/01 15:52:05 abs Exp $
#

.include "../../mk/bsd.prefs.mk"
#
.if ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "sparc"
DISTNAME=	${PKGNAME}.sparc-sun-solaris2.6
#
.elif (${MACHINE_ARCH} == "alpha")
DISTNAME=	${PKGNAME}.alpha-unknown-netbsd1.4
#
.elif (${MACHINE_ARCH} == "i386")
DISTNAME=	${PKGNAME}.i386-unknown-netbsd1.3
#
.elif (${MACHINE_ARCH} == "powerpc")
DISTNAME=	${PKGNAME}.powerpc-unknown-netbsd1.4
#
# XXX Not yet on ftp site
.elif (${MACHINE_ARCH} == "sparc")
DISTNAME=	${PKGNAME}.sparc-unknown-netbsd1.4
#
.else
DISTNAME=	${PKGNAME}
.endif
#
PKGNAME=	setiathome-3.03
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cdrom.com/pub/setiathome/ \
		ftp://alien.ssl.berkeley.edu/pub/ \
		ftp://setidata.ssl.berkeley.edu/pub/
EXTRACT_SUFX=	.tar

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://setiathome.ssl.berkeley.edu/
COMMENT=	Search for Extraterrestrial Intelligence - at home

ONLY_FOR_PLATFORM= NetBSD-*-alpha NetBSD-*-i386 NetBSD-*-powerpc SunOS-*-sparc

DIST_SUBDIR=    setiathome
DECOMPRESS_CMD=	${CAT}
NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/setiathome ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xsetiathome ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/man/cat1/setiathome.0

.include "../../mk/bsd.pkg.mk"
