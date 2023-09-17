# $NetBSD: Makefile,v 1.1 2023/09/17 08:53:21 adam Exp $

PKGNAME=	${DISTNAME:S/-/16-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql16-client>=${PKGVERSION_NOREV}:../../databases/postgresql16-client
DEPENDS+=	postgresql16-docs>=${PKGVERSION_NOREV}:../../databases/postgresql16-docs
DEPENDS+=	postgresql16-server>=${PKGVERSION_NOREV}:../../databases/postgresql16-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
