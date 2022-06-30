# $NetBSD: Makefile,v 1.39 2022/06/30 11:18:40 nia Exp $

DISTNAME=	exabgp-4.2.17
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Exa-Networks/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://github.com/Exa-Networks/exabgp/
COMMENT=	BGP swiss army knife
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_PKG_RESOURCES=	yes

USE_TOOLS+=	perl:run

REPLACE_PERL+=		etc/exabgp/run/dynamic-1.pl
REPLACE_PERL+=		etc/exabgp/run/watchdog-1.pl

REPLACE_PYTHON+=	etc/exabgp/run/*.run
REPLACE_PYTHON+=	etc/exabgp/run/*.py

CHECK_PORTABILITY_SKIP+=	dev/release/google

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/exabgp bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

pre-install:
	find ${WRKDIR} -name "*.orig" | xargs rm -f

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/exabgp.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/exabgp.conf.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
