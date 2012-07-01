# $NetBSD: Makefile,v 1.8 2012/07/01 19:21:13 morr Exp $

PKGNAME=	${DISTNAME:C/-/83-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql83-client>=${PKGVERSION_NOREV}:../../databases/postgresql83-client
DEPENDS+=	postgresql83-server>=${PKGVERSION_NOREV}:../../databases/postgresql83-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
