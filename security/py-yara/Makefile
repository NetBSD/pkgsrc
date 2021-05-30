# $NetBSD: Makefile,v 1.11 2021/05/30 01:16:28 khorben Exp $

DISTNAME=	yara-python-${YARA_VERSION}
PKGNAME=	${PYPKGPREFIX}-yara-${YARA_VERSION}
CATEGORIES=	security python
GITHUB_PROJECT=	yara-python

MASTER_SITES=	${MASTER_SITE_GITHUB:=VirusTotal/}

COMMENT=	Yara python bindings
LICENSE=	apache-2.0

.include "../../security/yara/Makefile.common"
.include "../../security/yara/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
