# $NetBSD: Makefile,v 1.19 2024/03/20 13:56:10 gutteridge Exp $

DISTNAME=	ReText-8.0.2
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	editors python
MASTER_SITES=	${MASTER_SITE_PYPI:=R/ReText/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/retext-project/retext
COMMENT=	Simple but powerful editor for Markdown and reStructuredText
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-enchant-[0-9]*:../../textproc/py-enchant
DEPENDS+=	${PYPKGPREFIX}-markups-[0-9]*:../../textproc/py-markups
DEPENDS+=	${PYPKGPREFIX}-qt6-[0-9]*:../../x11/py-qt6
DEPENDS+=	${PYPKGPREFIX}-sip-qt6-[0-9]*:../../x11/py-sip-qt6

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 # py-markups

USE_PKG_RESOURCES=	yes

.include "../../mk/bsd.prefs.mk"

# Workaround for PR#57445/50277 for netbsd-9 & netbsd-10 pre 2023-08-05
post-install:
.if ${OPSYS} == "NetBSD"
	${MV} ${DESTDIR}${PREFIX}/bin/retext ${DESTDIR}${PREFIX}/bin/retext-py
	${INSTALL_SCRIPT} ${FILESDIR}/retext.sh ${DESTDIR}${PREFIX}/bin/retext
	${SED} -i -e 's|@PREFIX@|${PREFIX}|g' ${DESTDIR}${PREFIX}/bin/retext
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
