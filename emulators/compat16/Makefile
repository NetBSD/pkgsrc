# $NetBSD: Makefile,v 1.2 2005/02/21 20:57:20 veego Exp $
#

DISTNAME=		compat16-${MACHINE_ARCH}-${VERSION}
PKGNAME=		compat16-${VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/Releases/formal-1.6/index.html
COMMENT=		Shared libraries for NetBSD 1.6 (and earlier) compatibility

VERSION=		1.6.0

ONLY_FOR_PLATFORM=	NetBSD-1.6[A-Z]*-i386 NetBSD-2*-i386

NO_MTREE=		# defined
NO_BUILD=		# defined
NO_CONFIGURE=		# defined
SHLIB_HANDLING=		NO

.include "../../mk/bsd.prefs.mk"

EMULSUBDIR=		emul/netbsd16

PLIST_SUBST+=		EMULSUBDIR=${EMULSUBDIR}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${EMULSUBDIR}
	(cd ${WRKDIR}; pax -rw usr ${PREFIX}/${EMULSUBDIR})

.include "../../mk/bsd.pkg.mk"
