# $NetBSD: Makefile,v 1.1.1.1 1999/08/06 16:37:22 hubertf Exp $
#

DISTNAME=	libgetopt-1.0
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/src/lib/libc/stdlib/ \
		ftp://ftp.de.netbsd.org/pub/NetBSD/NetBSD-current/src/lib/libc/stdlib/
DISTFILES=	getopt_long.c getopt_long.3

MAINTAINER=	hubertf@netbsd.org,mcr@netbsd.org

WRKSRC=		${WRKDIR}/libgetopt
# I have NFC why the mkdir in pre-extract doesn't work, so do it here:
EXTRACT_CMD=	${MKDIR} ${WRKSRC} && ${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
MANCOMPRESSED_IF_MANZ=  yes
INSTALL_TARGET=	install NOLINT=1 LIBDIR=${PREFIX}/lib MANDIR=${PREFIX}/man

post-extract:
		${CP} ${FILESDIR}/getopt.h ${WRKSRC}
		${CP} ${FILESDIR}/shlib_version ${WRKSRC}
		${CP} ${FILESDIR}/Makefile.libgetopt ${WRKSRC}/Makefile

post-install:
		${INSTALL_DATA} ${FILESDIR}/getopt.h ${PREFIX}/include/getopt.h

.include "../../mk/bsd.pkg.mk"
