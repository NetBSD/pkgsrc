# $NetBSD: Makefile,v 1.11 2024/11/11 07:28:49 wiz Exp $

DISTNAME=	ldapdomaindump-0.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/ldapdomaindump/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dirkjanm/ldapdomaindump
COMMENT=	Collection of Python classes for working with network protocols
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-ldap3>=2.7:../../databases/py-ldap3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in ldapdomaindump ldd2bloodhound ldd2pretty
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
