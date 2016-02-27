# $NetBSD: Makefile,v 1.6.6.1 2016/02/27 21:08:00 bsiegert Exp $

PKGNAME=	${DISTNAME:C/-/93-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql93-client>=${PKGVERSION_NOREV}:../../databases/postgresql93-client
DEPENDS+=	postgresql93-docs>=${PKGVERSION_NOREV}:../../databases/postgresql93-docs
DEPENDS+=	postgresql93-server>=${PKGVERSION_NOREV}:../../databases/postgresql93-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
