# $NetBSD: Makefile,v 1.15 2021/04/21 11:41:15 adam Exp $

PKGNAME=	${DISTNAME:S/-/11-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql11-client>=${PKGVERSION_NOREV}:../../databases/postgresql11-client
DEPENDS+=	postgresql11-docs>=${PKGVERSION_NOREV}:../../databases/postgresql11-docs
DEPENDS+=	postgresql11-server>=${PKGVERSION_NOREV}:../../databases/postgresql11-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
