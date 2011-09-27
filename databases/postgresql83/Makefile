# $NetBSD: Makefile,v 1.6 2011/09/27 11:03:59 adam Exp $

PKGNAME=	${DISTNAME:C/-/83-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql83-client>=${PKGVERSION_NOREV}:../../databases/postgresql83-client
DEPENDS+=	postgresql83-server>=${PKGVERSION_NOREV}:../../databases/postgresql83-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
