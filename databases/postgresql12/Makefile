# $NetBSD: Makefile,v 1.31 2023/11/08 13:18:30 wiz Exp $

PKGNAME=	${DISTNAME:S/-/12-/}
PKGREVISION=	3
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql12-client>=${PKGVERSION_NOREV}:../../databases/postgresql12-client
DEPENDS+=	postgresql12-docs>=${PKGVERSION_NOREV}:../../databases/postgresql12-docs
DEPENDS+=	postgresql12-server>=${PKGVERSION_NOREV}:../../databases/postgresql12-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
