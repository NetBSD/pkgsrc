# $NetBSD: Makefile,v 1.4.2.1 2017/06/13 18:41:37 bsiegert Exp $

PKGNAME=	${PYPKGPREFIX}-yara-${YAVER}
CATEGORIES=	security python

MASTER_SITES=	${MASTER_SITE_GITHUB:=VirusTotal/yara-python/archive/}

DIST_SUBDIR=	yara-python

COMMENT=	Yara python bindings

WRKSRC=		${WRKDIR}/yara-python-${YAVER}

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=   34 35 36

.include "../../security/yara/Makefile.common"
.include "../../security/yara/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
