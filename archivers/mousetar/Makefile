# $NetBSD: Makefile,v 1.3 2003/03/29 12:40:02 jmmv Exp $
#

DISTNAME=	mousetar-20021217
WRKSRC=		${WRKDIR}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/mouse/tar/
DISTFILES=	tar.c tar.man

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	none
COMMENT=	der Mouse's version of tar program

do-extract:
	for f in ${DISTFILES}; do					\
		${CP} ${DISTDIR}/$$f ${WRKDIR};				\
	done

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} tar.c -o mousetar

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mousetar ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tar.man ${PREFIX}/man/man1/mousetar.1

.include "../../mk/bsd.pkg.mk"
