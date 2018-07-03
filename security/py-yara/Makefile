# $NetBSD: Makefile,v 1.7 2018/07/03 05:03:32 adam Exp $

DISTNAME=	yara-python-${VERSION}
PKGNAME=	${PYPKGPREFIX}-yara-${VERSION}
CATEGORIES=	security python
GITHUB_PROJECT=	yara-python

MASTER_SITES=	${MASTER_SITE_GITHUB:=VirusTotal/}

COMMENT=	Yara python bindings

PYTHON_VERSIONS_INCOMPATIBLE=   34 35 36 37

.include "../../security/yara/Makefile.common"
.include "../../security/yara/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
