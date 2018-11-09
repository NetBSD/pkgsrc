# $NetBSD: Makefile,v 1.7 2018/11/09 18:12:26 adam Exp $

PKGNAME=	${DISTNAME:C/-/95-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql95-client>=${PKGVERSION_NOREV}:../../databases/postgresql95-client
DEPENDS+=	postgresql95-docs>=${PKGVERSION_NOREV}:../../databases/postgresql95-docs
DEPENDS+=	postgresql95-server>=${PKGVERSION_NOREV}:../../databases/postgresql95-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
