# $NetBSD: Makefile,v 1.3 2008/03/13 16:47:37 joerg Exp $

PKGNAME=	postgresql82-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql82-client>=${BASE_VERS}:../../databases/postgresql82-client
DEPENDS+=	postgresql82-server>=${BASE_VERS}:../../databases/postgresql82-server

.include "Makefile.common"

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
