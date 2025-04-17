# $NetBSD: Makefile,v 1.16 2025/04/17 21:50:08 wiz Exp $

PKGNAME=	${DISTNAME:S/-/15-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql15-client>=${PKGVERSION_NOREV}:../../databases/postgresql15-client
DEPENDS+=	postgresql15-docs>=${PKGVERSION_NOREV}:../../databases/postgresql15-docs
DEPENDS+=	postgresql15-server>=${PKGVERSION_NOREV}:../../databases/postgresql15-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
