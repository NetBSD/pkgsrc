# $NetBSD: Makefile,v 1.9 2007/09/07 22:12:23 jlam Exp $
#

DISTNAME=		free-1.0
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Displays memory usage


BUILD_DEFS+=	IPV6_READY

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/free ${PREFIX}/bin/free
	${INSTALL_MAN} ${FILESDIR}/free.1 ${PREFIX}/${PKGMANDIR}/man1/free.1

.include "../../mk/bsd.pkg.mk"
