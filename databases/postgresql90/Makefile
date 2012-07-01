# $NetBSD: Makefile,v 1.4 2012/07/01 19:42:06 morr Exp $

PKGNAME=	${DISTNAME:C/-/90-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql90-client>=${PKGVERSION_NOREV}:../../databases/postgresql90-client
DEPENDS+=	postgresql90-docs>=${PKGVERSION_NOREV}:../../databases/postgresql90-docs
DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
