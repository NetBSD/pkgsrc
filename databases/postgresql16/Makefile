# $NetBSD: Makefile,v 1.2 2023/10/24 22:08:37 wiz Exp $

PKGNAME=	${DISTNAME:S/-/16-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql16-client>=${PKGVERSION_NOREV}:../../databases/postgresql16-client
DEPENDS+=	postgresql16-docs>=${PKGVERSION_NOREV}:../../databases/postgresql16-docs
DEPENDS+=	postgresql16-server>=${PKGVERSION_NOREV}:../../databases/postgresql16-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
