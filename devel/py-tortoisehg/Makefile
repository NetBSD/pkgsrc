# $NetBSD: Makefile,v 1.67 2020/11/07 16:32:13 wiz Exp $

DISTNAME=		tortoisehg-5.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		https://www.mercurial-scm.org/release/tortoisehg/targz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://tortoisehg.bitbucket.io/
COMMENT=		GUI for Mercurial
LICENSE=		gnu-gpl-v2

REPLACE_PYTHON+=	thg

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.3.4nb1:../../textproc/py-sphinx1
DEPENDS+=	${PYPKGPREFIX}-iniparse>=0.4:../../textproc/py-iniparse
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.6:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-mercurial>=5.0.0:../../devel/py-mercurial

thg_icon=		/share/pixmaps/tortoisehg/icons/thg_logo.ico
SUBST_CLASSES+=		df
SUBST_STAGE.df=		post-configure
SUBST_MESSAGE.df=	Fixing icon reference in desktop file
SUBST_FILES.df=		contrib/thg.desktop
SUBST_SED.df=		-e 's:thg_logo:${PREFIX}${thg_icon}:1'

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/doc/tortoisehg

pre-build:
	${RUN} cd ${WRKSRC}/doc && ${MAKE_PROGRAM} SPHINXBUILD=sphinx-build-${PYVERSSUFFIX} html
	${RUN} rm ${WRKSRC}/doc/build/html/.buildinfo
	# conflicts with mercurial
	# https://bitbucket.org/tortoisehg/thg/issues/4629/tortoisehg-file-name-conflict-with
	${RM} ${WRKSRC}/hgext3rd/__init__.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/thg.desktop ${DESTDIR}${PREFIX}/share/applications/thg.desktop
	${INSTALL_DATA} ${WRKSRC}/COPYING.txt ${DESTDIR}${PREFIX}/share/doc/tortoisehg
	cd ${WRKSRC}/doc/build && pax -pp -rw html ${DESTDIR}${PREFIX}/share/doc/tortoisehg

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-qt5-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
