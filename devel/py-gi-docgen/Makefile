# $NetBSD: Makefile,v 1.11 2024/07/24 09:16:41 jperkin Exp $

DISTNAME=	gi_docgen-2024.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/gi_/gi-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gi_docgen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/gi-docgen
COMMENT=	Documentation tool for GObject-based libraries
LICENSE=	gnu-gpl-v3 AND apache-2.0 AND cc0-1.0-universal

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.2:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=1:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pygments>=2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-typogrify>=2:../../textproc/py-typogrify

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=0:../../textproc/py-tomli
.endif

PYTHON_SELF_CONFLICT=		yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing PREFIX.
SUBST_FILES.prefix=	gidocgen/utils.py
SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},g'

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_MESSAGE.mandir=	Fixing path man pages.
SUBST_FILES.mandir=	setup.cfg
SUBST_SED.mandir=	-e 's,^share/man,${PKGMANDIR},'
SUBST_NOOP_OK.mandir=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
