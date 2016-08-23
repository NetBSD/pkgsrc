# $NetBSD: Makefile,v 1.8 2016/08/23 06:28:16 adam Exp $

PKGNAME=	${DISTNAME:C/-/94-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql94-client>=${PKGVERSION_NOREV}:../../databases/postgresql94-client
DEPENDS+=	postgresql94-docs>=${PKGVERSION_NOREV}:../../databases/postgresql94-docs
DEPENDS+=	postgresql94-server>=${PKGVERSION_NOREV}:../../databases/postgresql94-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
