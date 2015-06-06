# $NetBSD: Makefile,v 1.1 2015/06/06 09:13:27 pettai Exp $

PKGNAME=	${PYPKGPREFIX}-yara-${YAVER}
CATEGORIES=	security python

COMMENT=	Yara python bindings

WRKSRC=		${WRKDIR}/yara-${YAVER}/yara-python

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=   33 34

.include "../../security/yara/Makefile.common"
.include "../../security/yara/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
