# $NetBSD: Makefile,v 1.2 2014/05/09 07:37:15 wiz Exp $

DISTNAME=	pymetar-0.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net python
MASTER_SITES=	http://www.schwarzvogel.de/pkgs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.schwarzvogel.de/software-pymetar.shtml
COMMENT=	Downloads weather reports
LICENSE=	gnu-gpl-v2 # or later

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.19

SUBST_CLASSES+=		manpath
SUBST_SED.manpath=	-e 's,share/man,${PKGMANDIR},'
SUBST_FILES.manpath+=	setup.py
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	Fix man page installation path.

CONFLICTS=	${PYPKGPREFIX}-pymetar-[0-9]*

post-extract:
	${MV} ${WRKSRC}/bin/pymetar ${WRKSRC}/bin/pymetar${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
