# $NetBSD: Makefile,v 1.5 2000/10/18 11:16:57 wiz Exp $
#

VERS=		1.2
DISTNAME=	libgetopt-${VERS}
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
# MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/src/lib/libc/stdlib/ \
#	 	ftp://ftp.de.netbsd.org/pub/NetBSD/NetBSD-current/src/lib/libc/stdlib/
DISTFILES=	getopt_long.c-${VERS} getopt_long.3-${VERS}

.if exists(/usr/include/getopt.h)
IGNORE=         "${PKGNAME} is part of your NetBSD distribution"
.endif

MAINTAINER=	hubertf@netbsd.org,mcr@netbsd.org

WRKSRC=		${WRKDIR}/libgetopt
# I have NFC why the mkdir in pre-extract doesn't work, so do it here:
EXTRACT_CMD=	${MKDIR} ${WRKSRC} && ${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
MANCOMPRESSED_IF_MANZ=  yes
INSTALL_TARGET=	install NOLINT=1 LIBDIR=${PREFIX}/lib MANDIR=${PREFIX}/man

post-extract:
		${CP} ${FILESDIR}/getopt.h ${WRKSRC}
		${CP} ${FILESDIR}/namespace.h ${WRKSRC}
		${CP} ${FILESDIR}/shlib_version ${WRKSRC}
		${CP} ${FILESDIR}/Makefile.libgetopt ${WRKSRC}/Makefile
		${MV} ${WRKSRC}/getopt_long.c-${VERS} ${WRKSRC}/getopt_long.c
		${MV} ${WRKSRC}/getopt_long.3-${VERS} ${WRKSRC}/getopt_long.3

post-install:
		${INSTALL_DATA} ${FILESDIR}/getopt.h ${PREFIX}/include/getopt.h

.include "../../mk/bsd.pkg.mk"
