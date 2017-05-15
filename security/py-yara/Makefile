# $NetBSD: Makefile,v 1.5 2017/05/15 15:27:31 khorben Exp $

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
