# $NetBSD: Makefile,v 1.8 2022/01/22 14:38:01 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-bonjour-${PKGVER}
DISTNAME=	bonjour-py-${PKGVER}
PKGVER=		0.3
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.mcs.anl.gov/fl/research/accessgrid/bonjour-py/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://www.mcs.anl.gov/fl/research/accessgrid/bonjour-py/
COMMENT=	Python interface to interact with Bonjour
LICENSE=	agtpl-license

EGDIR=		share/examples/py-bonjour
EGFILES=	browse.py query.py register.py serviceTypes.py \
		test.py wxBrowse.py
DOCDIR=		share/py-bonjour
DOCFILES=	COPYING.txt README

PYTHON_VERSIONS_ACCEPTED=	27 # Uses old exception syntax in 0.3
EGG_NAME=			PACKAGENAME-1.0

.for ee in ${EGFILES}
REPLACE_PYTHON+=	examples/${ee}
.endfor

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		setup.py
SUBST_SED.fix-paths=		-e 's,%PREFIX%,${PREFIX},g'

USE_LANGUAGES=	c

INSTALLATION_DIRS=	${EGDIR} ${DOCDIR}

post-install:
.for ff in ${EGFILES}
	${INSTALL_DATA}  ${WRKSRC}/examples/${ff} \
		${DESTDIR}${PREFIX}/${EGDIR}/${ff}
.endfor
.for ff in ${DOCFILES}
	${INSTALL_DATA}  ${WRKSRC}/${ff} \
		${DESTDIR}${PREFIX}/${DOCDIR}/${ff}
.endfor

.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
