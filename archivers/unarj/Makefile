# $NetBSD: Makefile,v 1.4 1998/04/20 11:56:18 frueauf Exp $
# FreeBSD Id: Makefile,v 1.6 1996/11/12 02:17:38 obrien Exp 
#

DISTNAME=       unarj
PKGNAME=	unarj-2.41
CATEGORIES=	archivers
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/arcers/
DISTFILES=      unarj241.tar.Z

MAINTAINER=     packages@netbsd.org

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ${DISTNAME} ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
