# $NetBSD: Makefile,v 1.2.2.1 2012/07/03 23:23:09 tron Exp $

PKGNAME=	${DISTNAME:C/-/91-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql91-client>=${PKGVERSION_NOREV}:../../databases/postgresql91-client
DEPENDS+=	postgresql91-docs>=${PKGVERSION_NOREV}:../../databases/postgresql91-docs
DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
