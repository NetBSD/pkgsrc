# $NetBSD: Makefile,v 1.8 2023/11/07 22:49:02 wiz Exp $

PKGNAME=		python-versions-check-1.6
CATEGORIES=		pkgtools

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://www.pkgsrc.org/
COMMENT=		Tool for checking Python versions in dependencies
LICENSE=		2-clause-bsd

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		# empty
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
REPLACE_PYTHON+=	python-versions-check

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	${CP} ${FILESDIR}/python-versions-check ${WRKSRC}

do-configure:

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/python-versions-check ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/python-versions-check.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
