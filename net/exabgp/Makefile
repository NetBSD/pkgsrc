# $NetBSD: Makefile,v 1.45 2025/04/15 07:20:37 adam Exp $

DISTNAME=	exabgp-4.2.25
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Exa-Networks/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://github.com/Exa-Networks/exabgp/
COMMENT=	BGP swiss army knife
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_TOOLS+=	perl:run

REPLACE_PERL+=		etc/exabgp/run/dynamic-1.pl
REPLACE_PERL+=		etc/exabgp/run/watchdog-1.pl

REPLACE_PYTHON+=	etc/exabgp/run/*.run
REPLACE_PYTHON+=	etc/exabgp/run/*.py

CHECK_PORTABILITY_SKIP+=	dev/release/google

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/exabgp bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

pre-install:
	${FIND} ${WRKDIR} -name "*.orig" | xargs ${RM} -f

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/exabgp.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/exabgp.conf.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

.include "../../lang/python/wheel.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
