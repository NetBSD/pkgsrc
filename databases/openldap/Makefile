# $NetBSD: Makefile,v 1.137 2012/03/13 19:57:10 adam Exp $

DISTNAME=	openldap-2.4.30
CATEGORIES=	databases
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://www.openldap.org/
COMMENT=	Lightweight Directory Access Protocol meta-package
LICENSE=	modified-bsd

META_PACKAGE=		yes

DEPENDS+=	openldap-client>=${PKGVERSION_NOREV}:../../databases/openldap-client
DEPENDS+=	openldap-server>=${PKGVERSION_NOREV}:../../databases/openldap-server
DEPENDS+=	openldap-doc>=${PKGVERSION_NOREV}:../../databases/openldap-doc

.include "../../mk/bsd.pkg.mk"
