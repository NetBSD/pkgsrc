# $NetBSD: Makefile,v 1.20 2005/03/10 21:15:36 tv Exp $
#

DISTNAME=	libgetopt-1.4.1
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Library for handling --long options

USE_LIBTOOL=	YES
WRKSRC=		${WRKDIR}/libgetopt

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/getopt.h) && empty(LOWER_OPSYS:Mirix5*)
PKG_SKIP_REASON= "${PKGNAME} is part of your ${OPSYS} distribution"
.endif

.if ${OPSYS} == "SunOS"
MAKEFLAGS+=	NETBSD_COMPATIBLE=YES
CFLAGS+=	-DREPLACE_GETOPT
.endif

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/getopt_long.? ${WRKSRC}
	${CP} ${FILESDIR}/getopt.h ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${COMPILE.c} getopt_long.c
	cd ${WRKSRC} && ${LIBTOOL} --mode=link ${LINK.c} -o libgetopt.la getopt_long.lo -version-info 5:1:4 -rpath ${PREFIX}/lib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libgetopt.la ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/getopt.h ${PREFIX}/include/
	${INSTALL_MAN} ${WRKSRC}/getopt_long.3 ${PREFIX}/man/man3/

.include "../../mk/bsd.pkg.mk"
