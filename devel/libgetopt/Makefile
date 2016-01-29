# $NetBSD: Makefile,v 1.38 2016/01/29 10:55:52 jperkin Exp $
#

DISTNAME=	libgetopt-1.4.6
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library for handling --long options
LICENSE=	2-clause-bsd AND original-bsd

CONFLICTS=	man-pages-[0-9]*

USE_LIBTOOL=	YES
WRKSRC=		${WRKDIR}/libgetopt

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "AIX" || ${OPSYS} == "HPUX" || \
	${OPSYS} == "OSF1" || ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
	
CFLAGS+=	-DREPLACE_GETOPT
.endif
CFLAGS.OSF1+=	-I.	# stdio.h includes <getopt.h>, make sure it's our copy

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/getopt_long.? ${WRKSRC}
	${CP} ${FILESDIR}/getopt.h ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${COMPILE.c} getopt_long.c
	cd ${WRKSRC} && ${LIBTOOL} --mode=link ${LINK.c} -o libgetopt.la getopt_long.lo -version-info 5:1:4 -rpath ${PREFIX}/lib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libgetopt.la \
		${DESTDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/getopt.h ${DESTDIR}${PREFIX}/include/
	${INSTALL_MAN} ${WRKSRC}/getopt_long.3 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/

.include "../../mk/bsd.pkg.mk"
