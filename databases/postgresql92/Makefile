# $NetBSD: Makefile,v 1.6 2014/05/29 23:35:32 wiz Exp $

PKGNAME=	${DISTNAME:C/-/92-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql92-client>=${PKGVERSION_NOREV}:../../databases/postgresql92-client
DEPENDS+=	postgresql92-docs>=${PKGVERSION_NOREV}:../../databases/postgresql92-docs
DEPENDS+=	postgresql92-server>=${PKGVERSION_NOREV}:../../databases/postgresql92-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
