# $NetBSD: Makefile,v 1.53 2023/06/10 14:35:29 wiz Exp $

PKGNAME=		revbump-3.3
CATEGORIES=		pkgtools

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://www.pkgsrc.org/
COMMENT=		Tool for bumping PKGREVISIONs (for pkgsrc developers)
LICENSE=		modified-bsd AND 2-clause-bsd

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		# empty
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
REPLACE_PYTHON+=	revbump.py

post-extract:
	${CP} ${FILESDIR}/revbump.py ${WRKSRC}

do-configure:

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/revbump.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/revbump.py.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
