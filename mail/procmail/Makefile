# $NetBSD: Makefile,v 1.12 1999/04/07 02:59:19 cjs Exp $
# FreeBSD Id: Makefile,v 1.24 1997/05/14 14:40:34 ache Exp
#

DISTNAME=       procmail-3.13.1
PKGNAME=        procmail-3.13.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.procmail.org/pub/procmail/

MAINTAINER=     packages@netbsd.org

INSTALL_TARGET= install-suid install.man
MAKE_ENV=	SHELL=/bin/sh

post-patch:
	${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h-orig
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|g' < ${WRKSRC}/config.h-orig \
		> ${WRKSRC}/config.h
	${MV} ${WRKSRC}/man/procmail.man ${WRKSRC}/man/procmail.man-orig
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|g' \
		< ${WRKSRC}/man/procmail.man-orig \
		> ${WRKSRC}/man/procmail.man

.include "../../mk/bsd.pkg.mk"
