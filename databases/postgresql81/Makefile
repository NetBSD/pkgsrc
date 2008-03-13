# $NetBSD: Makefile,v 1.4 2008/03/13 16:47:37 joerg Exp $

PKGNAME=	postgresql81-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql81-client>=${BASE_VERS}:../../databases/postgresql81-client
DEPENDS+=	postgresql81-server>=${BASE_VERS}:../../databases/postgresql81-server

.include "Makefile.common"

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
