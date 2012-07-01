# $NetBSD: Makefile,v 1.4 2012/07/01 19:30:23 morr Exp $

PKGNAME=	${DISTNAME:C/-/84-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql84-client>=${PKGVERSION_NOREV}:../../databases/postgresql84-client
DEPENDS+=	postgresql84-server>=${PKGVERSION_NOREV}:../../databases/postgresql84-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
