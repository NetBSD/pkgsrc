# $NetBSD: Makefile,v 1.16 2021/08/13 11:54:45 adam Exp $

PKGNAME=	${DISTNAME:S/-/12-/}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql12-client>=${PKGVERSION_NOREV}:../../databases/postgresql12-client
DEPENDS+=	postgresql12-docs>=${PKGVERSION_NOREV}:../../databases/postgresql12-docs
DEPENDS+=	postgresql12-server>=${PKGVERSION_NOREV}:../../databases/postgresql12-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
