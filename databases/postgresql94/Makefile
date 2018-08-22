# $NetBSD: Makefile,v 1.9 2018/08/22 09:43:24 wiz Exp $

PKGNAME=	${DISTNAME:C/-/94-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql94-client>=${PKGVERSION_NOREV}:../../databases/postgresql94-client
DEPENDS+=	postgresql94-docs>=${PKGVERSION_NOREV}:../../databases/postgresql94-docs
DEPENDS+=	postgresql94-server>=${PKGVERSION_NOREV}:../../databases/postgresql94-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
