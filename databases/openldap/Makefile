# $NetBSD: Makefile,v 1.155 2024/01/31 18:17:21 adam Exp $

.include "../../databases/openldap/Makefile.version"

CATEGORIES=	databases

MAINTAINER=	adam@NetBSD.org
COMMENT=	Lightweight Directory Access Protocol meta-package

META_PACKAGE=	yes

DEPENDS+=	openldap-client>=${PKGVERSION_NOREV}:../../databases/openldap-client
DEPENDS+=	openldap-server>=${PKGVERSION_NOREV}:../../databases/openldap-server
DEPENDS+=	openldap-doc>=${PKGVERSION_NOREV}:../../databases/openldap-doc

.include "../../mk/bsd.pkg.mk"
