# $NetBSD: Makefile,v 1.5 2022/06/30 11:18:46 nia Exp $

DISTNAME=	PACK-0.0.3
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://thesprawl.org/media/projects/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thesprawl.org/projects/pack/
COMMENT=	Password analysis and cracking kit
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-enchant-[0-9]*:../../textproc/py-enchant

USE_LANGUAGES=		# none
INSTALLATION_DIRS=	bin

REPLACE_PYTHON=		dictstat.py
REPLACE_PYTHON+=	maskgen.py
REPLACE_PYTHON+=	policygen.py
REPLACE_PYTHON+=	rulegen.py

do-build:

do-install:
	cd ${WRKSRC} && \
		${INSTALL_SCRIPT} *.py ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
