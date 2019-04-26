# $NetBSD: Makefile,v 1.8 2019/04/26 13:14:13 maya Exp $

DISTNAME=	yara-python-${VERSION}
PKGNAME=	${PYPKGPREFIX}-yara-${VERSION}
CATEGORIES=	security python
GITHUB_PROJECT=	yara-python

MASTER_SITES=	${MASTER_SITE_GITHUB:=VirusTotal/}

COMMENT=	Yara python bindings

PYTHON_VERSIONS_INCOMPATIBLE=    36 37

.include "../../security/yara/Makefile.common"
.include "../../security/yara/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
