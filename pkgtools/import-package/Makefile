# $NetBSD: Makefile,v 1.2 2023/02/12 11:24:46 tnn Exp $

PKGNAME=	import-package-1.1
CATEGORIES=	pkgtools

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://www.NetBSD.org/docs/pkgsrc/
COMMENT=	Tool for importing a package

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-extract:
	cd ${FILESDIR} && ${CP} import-package.sh import-package.1 ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/import-package.sh \
		${DESTDIR}${PREFIX}/bin/import-package
	${INSTALL_MAN} ${WRKSRC}/import-package.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
