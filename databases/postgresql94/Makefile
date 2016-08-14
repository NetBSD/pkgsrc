# $NetBSD: Makefile,v 1.7 2016/08/14 16:56:29 is Exp $

PKGNAME=	${DISTNAME:C/-/94-/}
PKGREVISION=	#
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql94-client>=${PKGVERSION_NOREV}:../../databases/postgresql94-client
DEPENDS+=	postgresql94-docs>=${PKGVERSION_NOREV}:../../databases/postgresql94-docs
DEPENDS+=	postgresql94-server>=${PKGVERSION_NOREV}:../../databases/postgresql94-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
