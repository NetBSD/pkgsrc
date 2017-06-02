# $NetBSD: Makefile,v 1.147 2017/06/02 08:29:56 adam Exp $

.include "../../databases/openldap/Makefile.version"

DISTNAME=	openldap-${OPENLDAP_VERSION}
CATEGORIES=	databases
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.openldap.org/
COMMENT=	Lightweight Directory Access Protocol meta-package
LICENSE=	modified-bsd

META_PACKAGE=		yes

DEPENDS+=	openldap-client>=${PKGVERSION_NOREV}:../../databases/openldap-client
DEPENDS+=	openldap-server>=${PKGVERSION_NOREV}:../../databases/openldap-server
DEPENDS+=	openldap-doc>=${PKGVERSION_NOREV}:../../databases/openldap-doc

.include "../../mk/bsd.pkg.mk"
