# $NetBSD: Makefile,v 1.18 2018/06/23 11:15:55 leot Exp $

DISTNAME=	fortune-strfile-0
CATEGORIES=	games
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tool to prepare a fortune database
LICENSE=	original-bsd

WRKSRC=			${WRKDIR}
USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		nroff groff
INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

do-extract:
	cp ${FILESDIR}/strfile.* ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
