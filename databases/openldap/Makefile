# $NetBSD: Makefile,v 1.154 2023/10/24 22:08:30 wiz Exp $

PKGREVISION= 1
.include "../../databases/openldap/Makefile.version"

CATEGORIES=	databases

MAINTAINER=	adam@NetBSD.org
COMMENT=	Lightweight Directory Access Protocol meta-package

META_PACKAGE=	yes

DEPENDS+=	openldap-client>=${PKGVERSION_NOREV}:../../databases/openldap-client
DEPENDS+=	openldap-server>=${PKGVERSION_NOREV}:../../databases/openldap-server
DEPENDS+=	openldap-doc>=${PKGVERSION_NOREV}:../../databases/openldap-doc

.include "../../mk/bsd.pkg.mk"
