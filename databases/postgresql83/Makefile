# $NetBSD: Makefile,v 1.7.2.1 2012/07/02 23:06:56 tron Exp $

PKGNAME=	${DISTNAME:C/-/83-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql83-client>=${PKGVERSION_NOREV}:../../databases/postgresql83-client
DEPENDS+=	postgresql83-server>=${PKGVERSION_NOREV}:../../databases/postgresql83-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
