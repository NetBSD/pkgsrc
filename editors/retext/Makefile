# $NetBSD: Makefile,v 1.24 2025/03/08 12:44:49 wiz Exp $

DISTNAME=	retext-8.1.0
PKGREVISION=	2
CATEGORIES=	editors python
MASTER_SITES=	${MASTER_SITE_PYPI:=R/ReText/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/retext-project/retext
COMMENT=	Simple but powerful editor for various markup formats
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
# Technically asciidoc is a dependency of py-markups, but we can't cleanly
# enable it there.
DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
DEPENDS+=	${PYPKGPREFIX}-enchant-[0-9]*:../../textproc/py-enchant
DEPENDS+=	${PYPKGPREFIX}-markups-[0-9]*:../../textproc/py-markups
DEPENDS+=	${PYPKGPREFIX}-qt6-[0-9]*:../../x11/py-qt6
DEPENDS+=	${PYPKGPREFIX}-sip-qt6-[0-9]*:../../x11/py-sip-qt6

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39  # py-markups

INSTALLATION_DIRS+=	share/applications

.include "../../mk/bsd.prefs.mk"

post-install:
# Workaround for PR#57445/50277 for netbsd-9 & netbsd-10 pre 2023-08-05.
.if ${OPSYS} == "NetBSD"
	${MV} ${DESTDIR}${PREFIX}/bin/retext ${DESTDIR}${PREFIX}/bin/retext-py
	${INSTALL_SCRIPT} ${FILESDIR}/retext.sh ${DESTDIR}${PREFIX}/bin/retext
	${SED} -i -e 's|@PREFIX@|${PREFIX}|g' ${DESTDIR}${PREFIX}/bin/retext
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
