# $NetBSD: Makefile,v 1.7 2007/08/23 18:20:33 jlam Exp $

PKGNAME=	libflashsupport-1.0.2098
DISTNAME=	libflashsupport-1-0-2098-i586
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.thinlincusergroup.se/forum/teknik/666951651/510222697/
EXTRACT_SUFX=	.rpm

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://labs.adobe.com/wiki/index.php/Flash_Player:Additional_Interface_Support_for_Linux
COMMENT=	Additional Interface Support for Linux Flash Player

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base openssl
EMUL_REQD=		suse>=9.1

EMUL_PKG_FMT=		rpm
RPM2PKG_STRIP=		3
RPM2PKG_PLIST=		# empty

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	share/doc

do-install:
	${INSTALL_LIB} ${WRKDIR}/libflashsupport.so \
		${PREFIX}/${EMULSUBDIR}/usr/lib
	${INSTALL_DATA} ${WRKDIR}/doc/libflashsupport-1.0/README \
		${PREFIX}/share/doc/libflashsupport.README

.include "../../mk/bsd.pkg.mk"
