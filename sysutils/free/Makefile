# $NetBSD: Makefile,v 1.8 2007/01/07 09:14:11 rillig Exp $
#

DISTNAME=		free-1.0
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Displays memory usage


# This pkg doesn't regard USE_INET6 (leave this comment for README-IPv6.html!)
WRKSRC=			${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/free ${PREFIX}/bin/free
	${INSTALL_MAN} ${FILESDIR}/free.1 ${PREFIX}/${PKGMANDIR}/man1/free.1

.include "../../mk/bsd.pkg.mk"
