# $NetBSD: Makefile,v 1.11 2002/12/07 02:38:53 schmonz Exp $
#

DISTNAME=	libgetopt-${VERS}
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
# MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/src/lib/libc/stdlib/ \
#	 	ftp://ftp.de.netbsd.org/pub/NetBSD/NetBSD-current/src/lib/libc/stdlib/
DISTFILES=	getopt_long.c-${VERS} getopt_long.3-${VERS}

MAINTAINER=	hubertf@netbsd.org,mcr@netbsd.org
COMMENT=	Library for handling --long options

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

.if exists(/usr/include/getopt.h)
PKG_SKIP_REASON= "${PKGNAME} is part of your ${OPSYS} distribution"
.endif

VERS=		1.3
WRKSRC=		${WRKDIR}/libgetopt
# I have NFC why the mkdir in pre-extract doesn't work, so do it here:
EXTRACT_CMD=	${MKDIR} ${WRKSRC} && ${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
MANCOMPRESSED_IF_MANZ=  yes
MAKE_FLAGS+=	LIBDIR=${PREFIX}/lib MANDIR=${PREFIX}/man
MAKE_FLAGS+=	MKLINT=no

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKEFLAGS+=	NETBSD_COMPATIBLE=YES
CFLAGS+=	-DREPLACE_GETOPT
.endif

.if ${OPSYS} != "NetBSD"
MAKE_FLAGS+=	MKMAN=no
MAN_INCLUDED=	'@comment '
.else
MAN_INCLUDED=
.endif

PLIST_SUBST+=	MAN_INCLUDED=${MAN_INCLUDED}

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
