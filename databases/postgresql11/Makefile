# $NetBSD: Makefile,v 1.2 2018/12/09 18:52:20 adam Exp $

PKGNAME=	${DISTNAME:C/-/11-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql11-client>=${PKGVERSION_NOREV}:../../databases/postgresql11-client
DEPENDS+=	postgresql11-docs>=${PKGVERSION_NOREV}:../../databases/postgresql11-docs
DEPENDS+=	postgresql11-server>=${PKGVERSION_NOREV}:../../databases/postgresql11-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
