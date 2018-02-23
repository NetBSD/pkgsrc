# $NetBSD: Makefile,v 1.4 2018/02/23 06:31:34 adam Exp $

PKGNAME=	plist-utils-20180222
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
