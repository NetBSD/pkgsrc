# $NetBSD: Makefile,v 1.16 2005/02/11 17:29:06 tv Exp $
#

DISTNAME=	libgetopt-${VERS}
PKGREVISION=	1
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
# MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/NetBSD-current/src/lib/libc/stdlib/ \
#	 	ftp://ftp.de.NetBSD.org/pub/NetBSD/NetBSD-current/src/lib/libc/stdlib/
DISTFILES=	getopt_long.c-${VERS} getopt_long.3-${VERS}

MAINTAINER=	hubertf@NetBSD.org,mcr@NetBSD.org
COMMENT=	Library for handling --long options

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

WRKSRC=		${WRKDIR}/libgetopt

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/getopt.h) && empty(LOWER_OPSYS:Mirix5*)
PKG_SKIP_REASON= "${PKGNAME} is part of your ${OPSYS} distribution"
.endif

VERS=		1.3
# I have NFC why the mkdir in pre-extract doesn't work, so do it here:
EXTRACT_CMD=	${MKDIR} ${WRKSRC} && ${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
MANCOMPRESSED_IF_MANZ=  yes
MAKE_FLAGS+=	LIBDIR=${PREFIX}/lib MANDIR=${PREFIX}/man
MAKE_FLAGS+=	MKLINT=no

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
