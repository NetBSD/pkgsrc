# $NetBSD: Makefile,v 1.10 2019/11/04 21:13:01 rillig Exp $

DISTNAME=	yara-python-${VERSION}
PKGNAME=	${PYPKGPREFIX}-yara-${VERSION}
CATEGORIES=	security python
GITHUB_PROJECT=	yara-python

MASTER_SITES=	${MASTER_SITE_GITHUB:=VirusTotal/}

COMMENT=	Yara python bindings

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../security/yara/Makefile.common"
.include "../../security/yara/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
