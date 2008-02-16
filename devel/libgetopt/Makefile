# $NetBSD: Makefile,v 1.27 2008/02/16 23:38:42 tnn Exp $
#

DISTNAME=	libgetopt-1.4.2
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library for handling --long options

NO_CHECKSUM=	YES
USE_LIBTOOL=	YES
WRKSRC=		${WRKDIR}/libgetopt

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "AIX" || ${OPSYS} == "HPUX"
CFLAGS+=	-DREPLACE_GETOPT
.endif

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3

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
	${INSTALL_MAN} ${WRKSRC}/getopt_long.3 ${PREFIX}/${PKGMANDIR}/man3/

.include "../../mk/bsd.pkg.mk"
