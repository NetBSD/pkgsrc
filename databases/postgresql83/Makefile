# $NetBSD: Makefile,v 1.7 2012/06/14 07:45:38 sbd Exp $

PKGNAME=	${DISTNAME:C/-/83-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql83-client>=${PKGVERSION_NOREV}:../../databases/postgresql83-client
DEPENDS+=	postgresql83-server>=${PKGVERSION_NOREV}:../../databases/postgresql83-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
