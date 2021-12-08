# $NetBSD: Makefile,v 1.20 2021/12/08 16:03:43 adam Exp $

PKGNAME=	${DISTNAME:S/-/11-/}
PKGREVISION=	2
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql11-client>=${PKGVERSION_NOREV}:../../databases/postgresql11-client
DEPENDS+=	postgresql11-docs>=${PKGVERSION_NOREV}:../../databases/postgresql11-docs
DEPENDS+=	postgresql11-server>=${PKGVERSION_NOREV}:../../databases/postgresql11-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
