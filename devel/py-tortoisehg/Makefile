# $NetBSD: Makefile,v 1.28 2016/02/06 11:07:10 wiz Exp $

DISTNAME=		tortoisehg-3.7.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		http://bitbucket.org/tortoisehg/targz/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tortoisehg.bitbucket.org/
COMMENT=		GUI for Mercurial
LICENSE=		gnu-gpl-v2

REPLACE_PYTHON+=	thg

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.3.4nb1:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-iniparse>=0.4:../../textproc/py-iniparse
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.6:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-mercurial>=2.8.1:../../devel/py-mercurial

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-iniparse, py-mercurial

thg_icon=		/share/pixmaps/tortoisehg/icons/thg_logo.ico
SUBST_CLASSES+=		df
SUBST_STAGE.df=		post-configure
SUBST_MESSAGE.df=	Fixing icon reference in desktop file
SUBST_FILES.df=		contrib/thg.desktop
SUBST_SED.df=		-e 's:thg_logo:${PREFIX}${thg_icon}:1'

pre-build:
	${RUN} cd ${WRKSRC}/doc && ${MAKE_PROGRAM} SPHINXBUILD=sphinx-build${PYVERSSUFFIX} html
	${RUN} rm ${WRKSRC}/doc/build/html/.buildinfo

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-qt4-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
