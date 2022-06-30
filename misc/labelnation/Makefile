# $NetBSD: Makefile,v 1.13 2022/06/30 11:18:37 nia Exp $

DISTNAME=		labelnation-1.231
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		https://www.red-bean.com/labelnation/

MAINTAINER=		solevis@solevis.net
HOMEPAGE=		https://www.red-bean.com/labelnation/
COMMENT=		Command-line label, business card printing program
LICENSE=		gnu-agpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON=		labelnation csv_to_ln

USE_LANGUAGES=		# none
NO_BUILD=		yes

DOCDIR=			share/doc/labelnation
EXAMPLESDIR=		share/examples/labelnation
INSTALLATION_DIRS=	bin ${DOCDIR} ${EXAMPLESDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/labelnation ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/csv_to_ln ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/*.* ${DESTDIR}${PREFIX}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.md ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
