# $NetBSD: Makefile,v 1.6 1998/12/26 15:46:10 garbled Exp $
# FreeBSD Id: Makefile,v 1.6 1996/11/12 02:17:38 obrien Exp 
#

DISTNAME=       unarj241
PKGNAME=	unarj-2.41
CATEGORIES=	archivers
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/arcers/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     packages@netbsd.org

WRKSRC=		${WRKDIR}/unarj

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} unarj ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
