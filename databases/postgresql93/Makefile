# $NetBSD: Makefile,v 1.8 2016/03/05 11:28:15 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/93-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql93-client>=${PKGVERSION_NOREV}:../../databases/postgresql93-client
DEPENDS+=	postgresql93-docs>=${PKGVERSION_NOREV}:../../databases/postgresql93-docs
DEPENDS+=	postgresql93-server>=${PKGVERSION_NOREV}:../../databases/postgresql93-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
