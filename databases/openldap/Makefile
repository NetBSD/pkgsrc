# $NetBSD: Makefile,v 1.143 2014/02/12 23:17:39 tron Exp $

.include "../../databases/openldap/Makefile.version"

DISTNAME=	openldap-${OPENLDAP_VERSION}
PKGREVISION=	1
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
