# $NetBSD: Makefile,v 1.3 2004/01/20 12:26:15 agc Exp $
#

DISTNAME=		free-1.0
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		hubertf@NetBSD.org
COMMENT=		Displays memory usage

USE_PKGINSTALL=		YES

# This pkg doesn't regard USE_INET6 (leave this comment for README-IPv6.html!)
WRKSRC=			${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/free ${PREFIX}/bin/free
	${INSTALL_MAN} ${FILESDIR}/free.1 ${PREFIX}/man/man1/free.1

.include "../../mk/bsd.pkg.mk"
