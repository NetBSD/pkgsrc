# $NetBSD: Makefile,v 1.8 1998/07/03 14:57:05 frueauf Exp $
# FreeBSD Id: Makefile,v 1.24 1997/05/14 14:40:34 ache Exp
#

DISTNAME=       procmail-3.11pre7
PKGNAME=        procmail-3.11p7
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/procmail/

MAINTAINER=     packages@netbsd.org

INSTALL_TARGET= install-suid install.man

post-patch:
	${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h-orig
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|g' < ${WRKSRC}/config.h-orig \
		> ${WRKSRC}/config.h

.include "../../mk/bsd.pkg.mk"
