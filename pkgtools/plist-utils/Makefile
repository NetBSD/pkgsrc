# $NetBSD: Makefile,v 1.5 2024/02/07 17:05:24 wiz Exp $

PKGNAME=	plist-utils-20240207
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Utility to facilitate management of PLIST files
LICENSE=	2-clause-bsd

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		nroff

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
PKGSRC_LOCKTYPE=	none	# avoid "bootstrapping problem"

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
