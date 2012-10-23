# $NetBSD: Makefile,v 1.13 2012/10/23 19:51:02 asau Exp $
#

DISTNAME=		free-1.0
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Displays memory usage

BUILD_DEFS+=	IPV6_READY

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/free ${DESTDIR}${PREFIX}/bin/free
	${INSTALL_MAN} ${FILESDIR}/free.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/free.1

.include "../../mk/bsd.pkg.mk"
