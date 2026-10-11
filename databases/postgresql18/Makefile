# $NetBSD: Makefile,v 1.4 2026/10/11 16:02:16 wiz Exp $

PKGNAME=	${DISTNAME:S/-/18-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql18-client>=${PKGVERSION_NOREV}:../../databases/postgresql18-client
DEPENDS+=	postgresql18-docs>=${PKGVERSION_NOREV}:../../databases/postgresql18-docs
DEPENDS+=	postgresql18-server>=${PKGVERSION_NOREV}:../../databases/postgresql18-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
