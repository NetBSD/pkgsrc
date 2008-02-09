# $NetBSD: Makefile,v 1.13 2008/02/09 23:42:59 tnn Exp $

DISTNAME=	fortune-strfile-0
CATEGORIES=	games
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tool to prepare a fortune database

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		nroff groff
INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

do-extract:
	cp ${FILESDIR}/strfile.* ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
