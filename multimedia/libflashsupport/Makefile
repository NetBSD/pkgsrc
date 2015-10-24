# $NetBSD: Makefile,v 1.16 2015/10/24 05:30:50 tsutsui Exp $

PKGNAME=	libflashsupport-4.2.2011
DISTNAME=	libflashsupport-v4.2-build2011
CATEGORIES=	multimedia
MASTER_SITES=	http://teokurebsd.org/netbsd/packages/distfiles/libflashsupport/

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	http://developer.opensound.com/
COMMENT=	Additional Interface Support for Linux Flash Player
LICENSE=	adobe-flashsupport-license

# On NetBSD, requires sufficiently new compat_linux.
NOT_FOR_PLATFORM=	NetBSD-[0-4]*-* NetBSD-5.[0-9].*-* Linux-*-*

EMUL_PLATFORMS=		linux-i386 linux-x86_64
EMUL_MODULES.linux=	base openssl
EMUL_REQD=		suse>=12.1

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
FLASH_ARCH=		i386
FLASH_LIBDIR=		lib
.elif ${EMUL_PLATFORM} == "linux-x86_64"
FLASH_ARCH=		x86_64
FLASH_LIBDIR=		lib64
.endif

PLIST_SUBST+=		LIBDIR=${FLASH_LIBDIR}

BUILD_DIRS=		# empty

INSTALLATION_DIRS=	${EMULSUBDIR}/usr/${FLASH_LIBDIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/${FLASH_ARCH}/libflashsupport.so \
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/usr/${FLASH_LIBDIR}

.include "../../mk/bsd.pkg.mk"
