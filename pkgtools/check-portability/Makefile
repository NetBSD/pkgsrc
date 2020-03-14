# $NetBSD: Makefile,v 1.7 2020/03/14 09:18:49 rillig Exp $

PKGNAME=	check-portability-19.4.3
CATEGORIES=	pkgtools
DISTFILES=	# none

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Check extracted files for typical portability issues
LICENSE=	2-clause-bsd

USE_TOOLS+=		cp
CHECK_PORTABILITY_SKIP=	* # avoid circular dependency
CHECK_PERMS_SKIP=	* # avoid circular dependency
USE_LANGUAGES=		c99
USE_BSD_MAKEFILE=	yes
AUTO_MKDIRS=		yes

do-extract:
	cd ${FILESDIR} && ${CP} -R . ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
