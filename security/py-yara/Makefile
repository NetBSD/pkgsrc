# $NetBSD: Makefile,v 1.4 2017/01/01 14:43:56 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-yara-${YAVER}
CATEGORIES=	security python

COMMENT=	Yara python bindings

WRKSRC=		${WRKDIR}/yara-${YAVER}/yara-python

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=   34 35 36

.include "../../security/yara/Makefile.common"
.include "../../security/yara/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
