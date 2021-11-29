# $NetBSD: Makefile,v 1.1 2021/11/29 17:19:50 wiz Exp $

DISTNAME=	asciinema-2.1.0
CATEGORIES=	multimedia python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asciinema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asciinema.org/
COMMENT=	Terminal session recorder
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27
INSTALLATION_DIRS=		${PKGMANDIR}/man1

post-install:
	cd ${DESTDIR}${PREFIX} && ${MV} share/man/man1/* ${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
