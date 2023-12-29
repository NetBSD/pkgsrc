# $NetBSD: Makefile,v 1.3 2023/12/29 18:24:58 adam Exp $

PKGREVISION= 1
.include "../../security/botan3/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Botan/botan3/}
COMMENT=	Python bindings for botan3

NO_BUILD=	yes
PY_PATCHPLIST=	yes

REPLACE_PYTHON=	src/python/botan3.py

INSTALLATION_DIRS+=	${PYSITELIB}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/python/botan3.py \
		${DESTDIR}${PREFIX}/${PYSITELIB}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../security/botan3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
