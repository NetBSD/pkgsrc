# $NetBSD: Makefile,v 1.1 2026/11/24 19:22:50 adam Exp $

PKGNAME=	${DISTNAME:S/-/19-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql19-client>=${PKGVERSION_NOREV}:../../databases/postgresql19-client
DEPENDS+=	postgresql19-docs>=${PKGVERSION_NOREV}:../../databases/postgresql19-docs
DEPENDS+=	postgresql19-server>=${PKGVERSION_NOREV}:../../databases/postgresql19-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
