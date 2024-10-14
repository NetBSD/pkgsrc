# $NetBSD: Makefile,v 1.103 2024/10/14 06:45:36 wiz Exp $

DISTNAME=	tortoisehg-6.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	https://www.mercurial-scm.org/release/tortoisehg/targz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tortoisehg.bitbucket.io/
COMMENT=	GUI for Mercurial
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx>=7.0.0:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-iniparse>=0.4:../../textproc/py-iniparse
DEPENDS+=	${PYPKGPREFIX}-mercurial>=5.0.0:../../devel/py-mercurial
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-qt6-qscintilla-[0-9]*:../../x11/py-qt6-qscintilla
DEPENDS+=	${PYPKGPREFIX}-sip-qt6-[0-9]*:../../x11/py-sip-qt6

USE_TOOLS+=	pax
MAKE_ENV+=	THG_QT_API=PyQt6

REPLACE_PYTHON+=	thg

thg_icon=		/share/pixmaps/tortoisehg/icons/thg_logo.ico
SUBST_CLASSES+=		df
SUBST_STAGE.df=		post-configure
SUBST_MESSAGE.df=	Fixing icon reference in desktop file
SUBST_FILES.df=		contrib/thg.desktop
SUBST_SED.df=		-e 's:thg_logo:${PREFIX}${thg_icon}:1'

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/doc/tortoisehg

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	39 # py-sphinx

pre-build:
	${RUN} cd ${WRKSRC}/doc && ${MAKE_PROGRAM} SPHINXBUILD=sphinx-build-${PYVERSSUFFIX} html
	${RM} -f ${WRKSRC}/doc/build/html/.buildinfo
	# conflicts with mercurial
	# https://foss.heptapod.net/mercurial/tortoisehg/thg/-/issues/4629
	${RM} -f ${WRKSRC}/hgext3rd/__init__.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/thg.desktop ${DESTDIR}${PREFIX}/share/applications/thg.desktop
	${INSTALL_DATA} ${WRKSRC}/COPYING.txt ${DESTDIR}${PREFIX}/share/doc/tortoisehg
	cd ${WRKSRC}/doc/build && ${PAX} -pp -rw html ${DESTDIR}${PREFIX}/share/doc/tortoisehg

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
