# $NetBSD: Makefile,v 1.13 2012/10/08 09:21:06 asau Exp $

DISTNAME=	libflashsupport-1.1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/pkgsrc/distfiles/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://labs.adobe.com/wiki/index.php/Flash_Player:Additional_Interface_Support_for_Linux
COMMENT=	Additional Interface Support for Linux Flash Player
LICENSE=		adobe-flashsupport-license

CONFLICTS=	libflashsupport-pulse-[0-9]* libflashsupport10-*

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base openssl
EMUL_REQD=		suse>=11.3

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	${EMULSUBDIR}/usr/lib

do-install:
	${INSTALL_LIB} ${WRKDIR}/libflashsupport.so \
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/usr/lib

.include "../../mk/bsd.pkg.mk"
