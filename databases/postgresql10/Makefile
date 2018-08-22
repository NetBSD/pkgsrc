# $NetBSD: Makefile,v 1.7 2018/08/22 09:43:23 wiz Exp $

PKGNAME=	${DISTNAME:C/-/10-/}
PKGREVISION=	2
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql10-client>=${PKGVERSION_NOREV}:../../databases/postgresql10-client
DEPENDS+=	postgresql10-docs>=${PKGVERSION_NOREV}:../../databases/postgresql10-docs
DEPENDS+=	postgresql10-server>=${PKGVERSION_NOREV}:../../databases/postgresql10-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
