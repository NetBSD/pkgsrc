# $NetBSD: Makefile,v 1.152 2020/02/10 15:13:06 adam Exp $

.include "../../databases/openldap/Makefile.version"

DISTNAME=	openldap-${OPENLDAP_VERSION}
CATEGORIES=	databases

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.openldap.org/
COMMENT=	Lightweight Directory Access Protocol meta-package
LICENSE=	modified-bsd

META_PACKAGE=	yes

DEPENDS+=	openldap-client>=${PKGVERSION_NOREV}:../../databases/openldap-client
DEPENDS+=	openldap-server>=${PKGVERSION_NOREV}:../../databases/openldap-server
DEPENDS+=	openldap-doc>=${PKGVERSION_NOREV}:../../databases/openldap-doc

.include "../../mk/bsd.pkg.mk"
