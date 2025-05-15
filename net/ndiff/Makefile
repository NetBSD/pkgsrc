# $NetBSD: Makefile,v 1.11 2025/05/15 15:44:41 adam Exp $

.include "../../net/nmap/Makefile.common"

PKGNAME=	${DISTNAME:S/nmap/ndiff/}

COMMENT=	Compares Nmap scans

WRKSRC=		${WRKDIR}/${DISTNAME}/ndiff

EXTRACT_ELEMENTS=	${DISTNAME}/ndiff

WHEEL_NAME=	${PKGNAME}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_MESSAGE.version=	Fixing version.
SUBST_FILES.version=	pyproject.toml
SUBST_SED.version=	-e 's,7.96,${PKGVERSION_NOREV},'

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
