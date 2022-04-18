# $NetBSD: Makefile,v 1.12 2022/04/18 19:10:41 adam Exp $

PKGNAME=	${DISTNAME:S/-/13-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql13-client>=${PKGVERSION_NOREV}:../../databases/postgresql13-client
DEPENDS+=	postgresql13-docs>=${PKGVERSION_NOREV}:../../databases/postgresql13-docs
DEPENDS+=	postgresql13-server>=${PKGVERSION_NOREV}:../../databases/postgresql13-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
