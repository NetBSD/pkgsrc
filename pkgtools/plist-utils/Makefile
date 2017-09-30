# $NetBSD: Makefile,v 1.3 2017/09/30 13:23:05 adam Exp $

PKGNAME=	plist-utils-20170813
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
