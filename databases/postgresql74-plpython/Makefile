# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:35 joerg Exp $

PKGNAME=		postgresql74-plpython-${BASE_VERS}
PKGREVISION=		1

COMMENT=		PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql74-server>=${BASE_VERS}:../../databases/postgresql74-server


.include "../../databases/postgresql74/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

BUILD_DIRS=		${WRKSRC}/src/pl/plpython

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/postgresql74-lib/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
