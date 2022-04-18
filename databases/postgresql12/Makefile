# $NetBSD: Makefile,v 1.21 2022/04/18 19:10:41 adam Exp $

PKGNAME=	${DISTNAME:S/-/12-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql12-client>=${PKGVERSION_NOREV}:../../databases/postgresql12-client
DEPENDS+=	postgresql12-docs>=${PKGVERSION_NOREV}:../../databases/postgresql12-docs
DEPENDS+=	postgresql12-server>=${PKGVERSION_NOREV}:../../databases/postgresql12-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
