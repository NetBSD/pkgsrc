# $NetBSD: Makefile,v 1.7 2020/08/14 06:56:25 adam Exp $

PKGNAME=	${DISTNAME:S/-/96-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql96-client>=${PKGVERSION_NOREV}:../../databases/postgresql96-client
DEPENDS+=	postgresql96-docs>=${PKGVERSION_NOREV}:../../databases/postgresql96-docs
DEPENDS+=	postgresql96-server>=${PKGVERSION_NOREV}:../../databases/postgresql96-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
