# $NetBSD: Makefile,v 1.10 2003/06/17 14:16:33 agc Exp $
#

DISTNAME=	gkermit
PKGNAME=	gkermit-1.00
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.columbia.edu/kermit/gkermit.html
COMMENT=	minimal implementation of the ``kermit'' protocol (GPL'd)

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	gkermit-1.00

USE_BUILDLINK2=	# defined
ALL_TARGET=	posix
MAKEFILE=	makefile
MAKE_ENV+=	KFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gkermit ${PREFIX}/bin/gkermit; \
	${INSTALL_MAN} ${WRKSRC}/gkermit.nr ${PREFIX}/man/man1/gkermit.1; \
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gkermit
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gkermit

.include "../../mk/bsd.pkg.mk"
