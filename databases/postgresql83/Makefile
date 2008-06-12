# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:20 joerg Exp $

PKGNAME=	postgresql83-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql83-client>=${BASE_VERS}:../../databases/postgresql83-client
DEPENDS+=	postgresql83-server>=${BASE_VERS}:../../databases/postgresql83-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
