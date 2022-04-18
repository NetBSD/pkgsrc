# $NetBSD: Makefile,v 1.30 2022/04/18 19:10:39 adam Exp $

PKGNAME=	${DISTNAME:S/-/10-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql10-client>=${PKGVERSION_NOREV}:../../databases/postgresql10-client
DEPENDS+=	postgresql10-docs>=${PKGVERSION_NOREV}:../../databases/postgresql10-docs
DEPENDS+=	postgresql10-server>=${PKGVERSION_NOREV}:../../databases/postgresql10-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
