# $NetBSD: Makefile,v 1.1.1.1 2003/08/29 18:51:05 hubertf Exp $
#

DISTNAME=		free-1.0
WRKSRC=			${WRKDIR}
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		hubertf@NetBSD.org
COMMENT=		Displays memory usage

USE_PKGINSTALL=		YES

# This pkg doesn't regard USE_INET6 (leave this comment for README-IPv6.html!)
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/free ${PREFIX}/bin/free

.include "../../mk/bsd.pkg.mk"
