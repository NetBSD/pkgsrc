# $NetBSD: Makefile,v 1.3 2020/03/12 00:05:36 rillig Exp $

PKGNAME=	check-portability-19.4.0
CATEGORIES=	pkgtools
DISTFILES=	# none

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Check extracted files for typical portability issues
LICENSE=	2-clause-bsd

USE_TOOLS+=		pax
CHECK_PORTABILITY_SKIP=	test-*.sh
USE_LANGUAGES=		c99
USE_BSD_MAKEFILE=	yes
AUTO_MKDIRS=		yes

do-extract:
	mkdir ${WRKSRC}
	cd ${FILESDIR} && ${PAX} -rw . ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
