# $NetBSD: Makefile,v 1.11 2011/10/16 04:16:49 obache Exp $
#

DISTNAME=		scapy-2.1.1
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.secdev.org/projects/scapy/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.secdev.org/projects/scapy/
COMMENT=		Interactive packet manipulation program

DEPENDS+=	${PYPKGPREFIX}-libpcap-[0-9]*:../../net/py-libpcap
DEPENDS+=	${PYPKGPREFIX}-libdnet-[0-9]*:../../net/py-libdnet
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=			yes
PYTHON_VERSIONS_ACCEPTED=	27 26 25

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
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/scapy
	${INSTALL_DATA} ${WRKSRC}/ethertypes ${DESTDIR}${PREFIX}/share/examples/scapy/

do-test:
	cd ${WRKSRC}/test && ${SETENV} PYTHON=${PYTHONBIN} ./run_tests

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
