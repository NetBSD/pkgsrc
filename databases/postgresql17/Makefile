# $NetBSD: Makefile,v 1.11 2026/10/11 16:02:16 wiz Exp $

PKGNAME=	${DISTNAME:S/-/17-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql17-client>=${PKGVERSION_NOREV}:../../databases/postgresql17-client
DEPENDS+=	postgresql17-docs>=${PKGVERSION_NOREV}:../../databases/postgresql17-docs
DEPENDS+=	postgresql17-server>=${PKGVERSION_NOREV}:../../databases/postgresql17-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
