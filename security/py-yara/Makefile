# $NetBSD: Makefile,v 1.9 2019/09/02 13:19:55 adam Exp $

DISTNAME=	yara-python-${VERSION}
PKGNAME=	${PYPKGPREFIX}-yara-${VERSION}
CATEGORIES=	security python
GITHUB_PROJECT=	yara-python

MASTER_SITES=	${MASTER_SITE_GITHUB:=VirusTotal/}

COMMENT=	Yara python bindings

PYTHON_VERSIONS_ACCEPTED=    27

.include "../../security/yara/Makefile.common"
.include "../../security/yara/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
