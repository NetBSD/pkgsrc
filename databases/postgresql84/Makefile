# $NetBSD: Makefile,v 1.6 2013/10/12 20:39:42 adam Exp $

PKGNAME=	${DISTNAME:C/-/84-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql84-client>=${PKGVERSION_NOREV}:../../databases/postgresql84-client
DEPENDS+=	postgresql84-server>=${PKGVERSION_NOREV}:../../databases/postgresql84-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
