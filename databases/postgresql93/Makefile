# $NetBSD: Makefile,v 1.4 2014/05/29 23:35:32 wiz Exp $

PKGNAME=	${DISTNAME:C/-/93-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql93-client>=${PKGVERSION_NOREV}:../../databases/postgresql93-client
DEPENDS+=	postgresql93-docs>=${PKGVERSION_NOREV}:../../databases/postgresql93-docs
DEPENDS+=	postgresql93-server>=${PKGVERSION_NOREV}:../../databases/postgresql93-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
