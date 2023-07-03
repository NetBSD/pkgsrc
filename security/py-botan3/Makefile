# $NetBSD: Makefile,v 1.1 2023/07/03 13:43:28 nros Exp $

.include "../../security/botan3/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Botan/botan3/}
COMMENT=	Python bindings for botan3

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	${PYSITELIB}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/python/botan3.py \
		${DESTDIR}${PREFIX}/${PYSITELIB}

.include "../../lang/python/extension.mk"
.include "../../security/botan3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
