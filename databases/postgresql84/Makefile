# $NetBSD: Makefile,v 1.3 2012/06/14 07:45:37 sbd Exp $

PKGNAME=	${DISTNAME:C/-/84-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql84-client>=${PKGVERSION_NOREV}:../../databases/postgresql84-client
DEPENDS+=	postgresql84-server>=${PKGVERSION_NOREV}:../../databases/postgresql84-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
