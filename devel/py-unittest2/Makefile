# $NetBSD: Makefile,v 1.8 2014/12/13 08:36:03 obache Exp $

DISTNAME=		unittest2-0.8.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=	http://pypi.python.org/packages/source/u/unittest2/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pypi.python.org/pypi/unittest2
COMMENT=		New features in unittest backported to Python 2.4+
LICENSE=		original-bsd

DEPENDS+=		${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=		${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse

DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR}
PLIST_SUBST+=		DOCDIR=${DOCDIR}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

SUBST_CLASSES+=		multi
SUBST_STAGE.multi=	pre-configure
SUBST_FILES.multi=	setup.py
SUBST_SED.multi=	-e 's,unit2,unit2-${PYVERSSUFFIX},'

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
