# $NetBSD: Makefile,v 1.3 2020/11/16 12:15:05 adam Exp $

PKGNAME=	${DISTNAME:S/-/13-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql13-client>=${PKGVERSION_NOREV}:../../databases/postgresql13-client
DEPENDS+=	postgresql13-docs>=${PKGVERSION_NOREV}:../../databases/postgresql13-docs
DEPENDS+=	postgresql13-server>=${PKGVERSION_NOREV}:../../databases/postgresql13-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
