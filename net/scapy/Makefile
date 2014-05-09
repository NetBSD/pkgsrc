# $NetBSD: Makefile,v 1.17 2014/05/09 07:37:16 wiz Exp $

DISTNAME=	scapy-2.2.0
CATEGORIES=	net
MASTER_SITES=	http://www.secdev.org/projects/scapy/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.secdev.org/projects/scapy/
COMMENT=	Interactive packet manipulation program
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-libpcap-[0-9]*:../../net/py-libpcap
DEPENDS+=	${PYPKGPREFIX}-libdnet-[0-9]*:../../net/py-libdnet
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline

NO_BUILD=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-libpcap, py-libdnet

INSTALLATION_DIRS+=	share/examples/scapy

.include "options.mk"

CONF_FILES=	${PREFIX}/share/examples/scapy/ethertypes \
		${PKG_SYSCONFDIR}/ethertypes

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	scapy/data.py
SUBST_SED.config=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
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
