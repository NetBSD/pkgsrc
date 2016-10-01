# $NetBSD: Makefile,v 1.1 2016/10/01 18:37:15 kamil Exp $
#

PKGNAME=	plist-utils-20160731
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Utility to facilitate management of PLIST files
LICENSE=	2-clause-bsd

USE_BSD_MAKEFILE=	yes
USE_TOOLS=		nroff

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
PKGSRC_LOCKTYPE=	none	# avoid "bootstrapping problem"

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
