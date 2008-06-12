# $NetBSD: Makefile,v 1.14 2008/06/12 02:14:30 joerg Exp $

DISTNAME=	fortune-strfile-0
CATEGORIES=	games
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tool to prepare a fortune database

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		nroff groff
INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

do-extract:
	cp ${FILESDIR}/strfile.* ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
