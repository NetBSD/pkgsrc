# $NetBSD: Makefile,v 1.11 2001/09/09 20:36:09 agc Exp $
# FreeBSD Id: Makefile,v 1.7 1997/08/10 22:31:09 fenner Exp 
#

DISTNAME=       arc521e.pl8
PKGNAME=        arc-5.21e
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=     packages@netbsd.org
COMMENT=	Create & extract files from DOS .ARC files

RESTRICTED=	"Do not modify. Do not charge for redistribution"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

WRKSRC=			${WRKDIR}
USE_BUILDLINK_ONLY=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arc ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/marc ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/arc.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
