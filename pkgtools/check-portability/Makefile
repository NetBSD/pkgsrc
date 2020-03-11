# $NetBSD: Makefile,v 1.1 2020/03/11 19:15:03 rillig Exp $

PKGNAME=	check-portability-19.4.0
CATEGORIES=	pkgtools
DISTFILES=	# none

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Check extracted files for typical portability issues
LICENSE=	2-clause-bsd

USE_TOOLS+=	pax
USE_LANGUAGES=	c99
MAKE_ENV+=	BINDIR=${PREFIX}/bin
AUTO_MKDIRS=	yes

CHECK_PORTABILITY_SKIP=	demo

do-extract:
	mkdir ${WRKSRC}
	cd ${FILESDIR} && ${PAX} -rw . ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
