# $NetBSD: Makefile,v 1.10 2020/06/02 08:23:27 adam Exp $

PKGNAME=	${DISTNAME:S/-/11-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql11-client>=${PKGVERSION_NOREV}:../../databases/postgresql11-client
DEPENDS+=	postgresql11-docs>=${PKGVERSION_NOREV}:../../databases/postgresql11-docs
DEPENDS+=	postgresql11-server>=${PKGVERSION_NOREV}:../../databases/postgresql11-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
