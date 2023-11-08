# $NetBSD: Makefile,v 1.3 2023/11/08 13:18:34 wiz Exp $

PKGNAME=	${DISTNAME:S/-/16-/}
PKGREVISION=	2
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql16-client>=${PKGVERSION_NOREV}:../../databases/postgresql16-client
DEPENDS+=	postgresql16-docs>=${PKGVERSION_NOREV}:../../databases/postgresql16-docs
DEPENDS+=	postgresql16-server>=${PKGVERSION_NOREV}:../../databases/postgresql16-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
