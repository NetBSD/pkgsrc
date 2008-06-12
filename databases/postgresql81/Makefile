# $NetBSD: Makefile,v 1.5 2008/06/12 02:14:19 joerg Exp $

PKGNAME=	postgresql81-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql81-client>=${BASE_VERS}:../../databases/postgresql81-client
DEPENDS+=	postgresql81-server>=${BASE_VERS}:../../databases/postgresql81-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
