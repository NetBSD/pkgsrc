# $NetBSD: Makefile,v 1.4 2020/01/18 21:49:03 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/96-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql96-client>=${PKGVERSION_NOREV}:../../databases/postgresql96-client
DEPENDS+=	postgresql96-docs>=${PKGVERSION_NOREV}:../../databases/postgresql96-docs
DEPENDS+=	postgresql96-server>=${PKGVERSION_NOREV}:../../databases/postgresql96-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
