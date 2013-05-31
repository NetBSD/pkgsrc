# $NetBSD: Makefile,v 1.4 2013/05/31 12:39:56 wiz Exp $

PKGNAME=	${DISTNAME:C/-/91-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql91-client>=${PKGVERSION_NOREV}:../../databases/postgresql91-client
DEPENDS+=	postgresql91-docs>=${PKGVERSION_NOREV}:../../databases/postgresql91-docs
DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
