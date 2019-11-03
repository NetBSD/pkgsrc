# $NetBSD: Makefile,v 1.29 2019/11/03 11:45:52 rillig Exp $

DISTNAME=	scapy-2.3.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=secdev/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.secdev.org/projects/scapy/
COMMENT=	Interactive packet manipulation program
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-libpcap-[0-9]*:../../net/py-libpcap
DEPENDS+=	${PYPKGPREFIX}-libdnet-[0-9]*:../../net/py-libdnet
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline

NO_BUILD=	yes

PYTHON_VERSIONS_ACCEPTED=	27 # py-libpcap, py-libdnet

INSTALLATION_DIRS+=	share/examples/scapy

.include "options.mk"

CONF_FILES=	${PREFIX}/share/examples/scapy/ethertypes \
		${PKG_SYSCONFDIR}/ethertypes

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	scapy/data.py setup.py
SUBST_VARS.config=	PKG_SYSCONFDIR
SUBST_SED.config+=	-e "s|share/man|${PKGMANDIR}|g"
SUBST_MESSAGE.config=	Fixing paths.

post-extract:
	${CP} ${FILESDIR}/ethertypes ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/ethertypes ${DESTDIR}${PREFIX}/share/examples/scapy/

do-test:
	cd ${WRKSRC}/test && ${SETENV} PYTHON=${PYTHONBIN} ./run_tests

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
