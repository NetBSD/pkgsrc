# $NetBSD: Makefile,v 1.1.1.1 2004/10/10 12:38:21 jdolecek Exp $

PKGNAME=		postgresql74-plpython-${BASE_VERS}
COMMENT=		PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql74-server>=${BASE_VERS}:../../databases/postgresql74-server

USE_BUILDLINK3=		yes

.include "../postgresql74/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-python

BUILD_DIRS=		${WRKSRC}/src/pl/plpython

.include "../../security/openssl/buildlink3.mk"
.include "../postgresql74-lib/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
