# $NetBSD: Makefile,v 1.6 1999/05/22 19:54:08 tv Exp $
# FreeBSD Id: Makefile,v 1.7 1997/08/10 22:31:09 fenner Exp 
#

DISTNAME=       arc521e.pl8
PKGNAME=        arc-5.21e
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=     packages@netbsd.org

NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arc ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/marc ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/arc.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
