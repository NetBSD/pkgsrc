# $NetBSD: Makefile,v 1.150 2020/01/18 21:48:57 jperkin Exp $

PKGREVISION= 1
.include "../../databases/openldap/Makefile.version"

DISTNAME=	openldap-${OPENLDAP_VERSION}
CATEGORIES=	databases

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.openldap.org/
COMMENT=	Lightweight Directory Access Protocol meta-package
LICENSE=	modified-bsd

META_PACKAGE=	yes

DEPENDS+=	openldap-client>=${PKGVERSION_NOREV}:../../databases/openldap-client
DEPENDS+=	openldap-server>=${PKGVERSION_NOREV}:../../databases/openldap-server
DEPENDS+=	openldap-doc>=${PKGVERSION_NOREV}:../../databases/openldap-doc

.include "../../mk/bsd.pkg.mk"
