# $NetBSD: Makefile,v 1.9 2003/03/29 12:40:19 jmmv Exp $
#

DISTNAME=	gkermit
PKGNAME=	gkermit-1.00
WRKSRC=		${WRKDIR}
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.columbia.edu/kermit/gkermit.html
COMMENT=	minimal implementation of the ``kermit'' protocol (GPL'd)

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
