# $NetBSD: Makefile,v 1.11 2008/03/13 16:47:37 joerg Exp $

PKGNAME=	postgresql80-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql80-client>=${BASE_VERS}:../../databases/postgresql80-client
DEPENDS+=	postgresql80-server>=${BASE_VERS}:../../databases/postgresql80-server

.include "Makefile.common"

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
