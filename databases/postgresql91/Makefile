# $NetBSD: Makefile,v 1.10.6.1 2016/02/27 16:33:30 bsiegert Exp $

PKGNAME=	${DISTNAME:C/-/91-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql91-client>=${PKGVERSION_NOREV}:../../databases/postgresql91-client
DEPENDS+=	postgresql91-docs>=${PKGVERSION_NOREV}:../../databases/postgresql91-docs
DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
