# $NetBSD: Makefile,v 1.58 2023/08/14 05:25:05 wiz Exp $

PKGNAME=		revbump-3.5
PKGREVISION=		1
CATEGORIES=		pkgtools

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://www.pkgsrc.org/
COMMENT=		Tool for bumping PKGREVISIONs (for pkgsrc developers)
LICENSE=		2-clause-bsd

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		# empty
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
REPLACE_PYTHON+=	revbump.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	${CP} ${FILESDIR}/revbump.py ${WRKSRC}

do-configure:

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/revbump.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/revbump.py.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
