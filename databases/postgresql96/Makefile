# $NetBSD: Makefile,v 1.15 2021/10/21 07:46:34 wiz Exp $

PKGNAME=	${DISTNAME:S/-/96-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql96-client>=${PKGVERSION_NOREV}:../../databases/postgresql96-client
DEPENDS+=	postgresql96-docs>=${PKGVERSION_NOREV}:../../databases/postgresql96-docs
DEPENDS+=	postgresql96-server>=${PKGVERSION_NOREV}:../../databases/postgresql96-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
