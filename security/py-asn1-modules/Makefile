# $NetBSD: Makefile,v 1.4 2017/04/08 21:25:26 adam Exp $

DISTNAME=	pyasn1-modules-0.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyasn1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyasn1.sourceforge.net/
COMMENT=	Modules for ITU Abstract Syntax Notification for Python
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.5:../../security/py-asn1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
