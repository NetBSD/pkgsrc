# $NetBSD: Makefile,v 1.5 2024/05/29 16:31:51 adam Exp $

PKGNAME=	${DISTNAME:S/-/16-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql16-client>=${PKGVERSION_NOREV}:../../databases/postgresql16-client
DEPENDS+=	postgresql16-docs>=${PKGVERSION_NOREV}:../../databases/postgresql16-docs
DEPENDS+=	postgresql16-server>=${PKGVERSION_NOREV}:../../databases/postgresql16-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
