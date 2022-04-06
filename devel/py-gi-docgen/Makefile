# $NetBSD: Makefile,v 1.1 2022/04/06 06:02:34 wiz Exp $

DISTNAME=	gi-docgen-2022.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gi-docgen/}

OWNER=		pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/gi-docgen
COMMENT=	Documentation tool for GObject-based libraries
LICENSE=	gnu-gpl-v3 AND apache-2.0 AND cc0-1.0-universal

DEPENDS+=	${PYPKGPREFIX}-markdown>=3:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=1:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-pygments>=2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-toml>=0:../../textproc/py-toml
DEPENDS+=	${PYPKGPREFIX}-typogrify>=2:../../textproc/py-typogrify
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_SELF_CONFLICT=		yes

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
