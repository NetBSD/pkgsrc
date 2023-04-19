# $NetBSD: Makefile,v 1.13 2023/04/19 08:09:31 adam Exp $

PKGNAME=	${DISTNAME:S/-/14-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql14-client>=${PKGVERSION_NOREV}:../../databases/postgresql14-client
DEPENDS+=	postgresql14-docs>=${PKGVERSION_NOREV}:../../databases/postgresql14-docs
DEPENDS+=	postgresql14-server>=${PKGVERSION_NOREV}:../../databases/postgresql14-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
