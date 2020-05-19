# $NetBSD: Makefile,v 1.4 2020/05/19 12:39:04 adam Exp $

DISTNAME=	ldapdomaindump-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/ldapdomaindump/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dirkjanm/ldapdomaindump
COMMENT=	Collection of Python classes for working with network protocols
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-ldap3>=2.6:../../databases/py-ldap3

USE_LANGUAGES=	# none

post-install:
.for bin in ldapdomaindump ldd2bloodhound
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
