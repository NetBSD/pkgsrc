# $NetBSD: Makefile,v 1.11 2003/07/17 21:49:55 grant Exp $
#

.include "../../mk/bsd.prefs.mk"
#
.if ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "sparc"
DISTNAME=	${PKGNAME_NOREV}.sparc-sun-solaris2.6
#
.elif (${MACHINE_ARCH} == "alpha")
DISTNAME=	${PKGNAME_NOREV}.alpha-unknown-netbsd1.4
#
.elif (${MACHINE_ARCH} == "i386")
DISTNAME=	${PKGNAME_NOREV}.i386-unknown-netbsd1.3
#
.elif (${MACHINE_ARCH} == "powerpc")
DISTNAME=	${PKGNAME_NOREV}.powerpc-unknown-netbsd1.4
#
# XXX Not yet on ftp site
.elif (${MACHINE_ARCH} == "sparc")
DISTNAME=	${PKGNAME_NOREV}.sparc-unknown-netbsd1.4
#
.else
DISTNAME=	${PKGNAME_NOREV}
.endif
#
PKGNAME=	setiathome-3.03
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cdrom.com/pub/setiathome/ \
		ftp://alien.ssl.berkeley.edu/pub/ \
		ftp://setidata.ssl.berkeley.edu/pub/
EXTRACT_SUFX=	.tar

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://setiathome.ssl.berkeley.edu/
COMMENT=	Search for Extraterrestrial Intelligence - at home

ONLY_FOR_PLATFORM= NetBSD-*-alpha NetBSD-*-i386 NetBSD-*-powerpc SunOS-*-sparc

DIST_SUBDIR=    setiathome
DECOMPRESS_CMD=	${CAT}
NO_BUILD=	yes
USE_PKGINSTALL=	yes

RCD_SCRIPTS=	setiathome

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/setiathome ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xsetiathome ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/man/cat1/setiathome.0

.include "../../mk/bsd.pkg.mk"
