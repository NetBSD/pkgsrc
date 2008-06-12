# $NetBSD: Makefile,v 1.4 2008/06/12 02:14:19 joerg Exp $

PKGNAME=	postgresql82-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql82-client>=${BASE_VERS}:../../databases/postgresql82-client
DEPENDS+=	postgresql82-server>=${BASE_VERS}:../../databases/postgresql82-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
