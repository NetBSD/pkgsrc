# $NetBSD: Makefile,v 1.8 2023/01/17 11:54:39 adam Exp $

DISTNAME=	ldapdomaindump-0.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/ldapdomaindump/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dirkjanm/ldapdomaindump
COMMENT=	Collection of Python classes for working with network protocols
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-ldap3>=2.7:../../databases/py-ldap3

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	dns

post-install:
.for bin in ldapdomaindump ldd2bloodhound ldd2pretty
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
