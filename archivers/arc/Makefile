# $NetBSD: Makefile,v 1.15 2003/06/02 01:21:52 jschauma Exp $
# FreeBSD Id: Makefile,v 1.7 1997/08/10 22:31:09 fenner Exp
#

DISTNAME=       arc521e.pl8
PKGNAME=        arc-5.21e
WRKSRC=		${WRKDIR}
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=     tech-pkg@netbsd.org
COMMENT=	Create & extract files from DOS .ARC files

RESTRICTED=	"Do not modify. Do not charge for redistribution"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arc ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/marc ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/arc.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
