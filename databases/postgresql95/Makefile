# $NetBSD: Makefile,v 1.16 2021/05/18 11:56:20 adam Exp $

PKGNAME=	${DISTNAME:S/-/95-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql95-client>=${PKGVERSION_NOREV}:../../databases/postgresql95-client
DEPENDS+=	postgresql95-docs>=${PKGVERSION_NOREV}:../../databases/postgresql95-docs
DEPENDS+=	postgresql95-server>=${PKGVERSION_NOREV}:../../databases/postgresql95-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
