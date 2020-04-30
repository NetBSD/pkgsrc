# $NetBSD: Makefile,v 1.2 2020/04/30 12:11:10 nikita Exp $

DISTNAME=	ldapdomaindump-0.9.1
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/ldapdomaindump/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dirkjanm/ldapdomaindump
COMMENT=	Collection of Python classes for working with network protocols
LICENSE=	apache-1.1

DEPENDS+=	${PYPKGPREFIX}-ldap3-[0-9]*:../../databases/py-ldap3
DEPENDS+=	${PYPKGPREFIX}-dnspython-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
