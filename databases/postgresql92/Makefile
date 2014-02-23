# $NetBSD: Makefile,v 1.5 2014/02/23 11:25:53 adam Exp $

PKGNAME=	${DISTNAME:C/-/92-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql92-client>=${PKGVERSION_NOREV}:../../databases/postgresql92-client
DEPENDS+=	postgresql92-docs>=${PKGVERSION_NOREV}:../../databases/postgresql92-docs
DEPENDS+=	postgresql92-server>=${PKGVERSION_NOREV}:../../databases/postgresql92-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
