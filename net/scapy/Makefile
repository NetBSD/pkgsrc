# $NetBSD: Makefile,v 1.38 2022/01/05 15:41:18 wiz Exp $

DISTNAME=	scapy-2.4.5
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=secdev/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scapy.net/
COMMENT=	Interactive packet manipulation program
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes

INSTALLATION_DIRS+=	share/examples/scapy

USE_PKG_RESOURCES=	yes

.include "options.mk"

CONF_FILES=	${PREFIX}/share/examples/scapy/ethertypes \
		${PKG_SYSCONFDIR}/ethertypes

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	scapy/data.py setup.py
SUBST_VARS.config=	PKG_SYSCONFDIR
SUBST_SED.config+=	-e "s|share/man|${PKGMANDIR}|g"
SUBST_MESSAGE.config=	Fixing paths.

TEST_DEPENDS+=	tcpreplay-[0-9]*:../../net/tcpreplay

post-extract:
	${CP} ${FILESDIR}/ethertypes ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/ethertypes ${DESTDIR}${PREFIX}/share/examples/scapy/

DATE_VAL=	${DATE} "+%Y%m%d-%H%M%S"

do-test:
	cd ${WRKSRC}/test && ${SETENV} PYTHON=${PYTHONBIN} ./run_tests \
		-t regression.uts -f html -K ipv6 -l \
		-o /tmp/scapy_regression_test_${DATE_VAL:sh}.html

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
