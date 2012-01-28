# $NetBSD: Makefile,v 1.1.1.1 2012/01/28 16:22:10 is Exp $

PKGNAME=	libflashsupport-1.0.2098
DISTNAME=	libflashsupport-1-0-2098-i586
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.thinlincusergroup.se/forum/teknik/666951651/510222697/
EXTRACT_SUFX=	.rpm

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://labs.adobe.com/wiki/index.php/Flash_Player:Additional_Interface_Support_for_Linux
COMMENT=	Additional Interface Support for Linux Flash Player

CONFLICTS=	libflashsupport-pulse-[0-9]* libflashsupport-[0-9]*

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base openssl
EMUL_REQD=		suse>=9.1

EMUL_PKG_FMT=		rpm
RPM2PKG_STRIP=		3
RPM2PKG_PLIST=		# empty

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	share/doc ${EMULSUBDIR}/usr/lib

do-install:
	${INSTALL_LIB} ${WRKDIR}/libflashsupport.so \
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/usr/lib
	${INSTALL_DATA} ${WRKDIR}/doc/libflashsupport-1.0/README \
		${DESTDIR}${PREFIX}/share/doc/libflashsupport.README

.include "../../mk/bsd.pkg.mk"
