# $NetBSD: Makefile,v 1.12 2007/03/15 20:46:51 joerg Exp $

DISTNAME=	fortune-strfile-0
CATEGORIES=	games
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tool to prepare a fortune database

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
USE_BSD_MAKEFILE=	yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

do-extract:
	cp ${FILESDIR}/strfile.* ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
