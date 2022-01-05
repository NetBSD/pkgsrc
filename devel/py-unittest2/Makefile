# $NetBSD: Makefile,v 1.15 2022/01/05 15:41:08 wiz Exp $

DISTNAME=		unittest2-1.1.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel python
MASTER_SITES=		${MASTER_SITE_PYPI:=u/unittest2/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/unittest2
COMMENT=		New features in unittest backported to Python 2.4+
LICENSE=		original-bsd

DEPENDS+=		${PYPKGPREFIX}-six>=1.4:../../lang/py-six
DEPENDS+=		${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
DEPENDS+=		${PYPKGPREFIX}-traceback2-[0-9]*:../../devel/py-traceback2
DEPENDS+=		${PYPKGPREFIX}-linecache2-[0-9]*:../../devel/py-linecache2

DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR}
PLIST_SUBST+=		DOCDIR=${DOCDIR}

SUBST_CLASSES+=		multi
SUBST_STAGE.multi=	pre-configure
SUBST_FILES.multi=	setup.py
SUBST_SED.multi=	-e 's,unit2,unit2-${PYVERSSUFFIX},'

USE_PKG_RESOURCES=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
