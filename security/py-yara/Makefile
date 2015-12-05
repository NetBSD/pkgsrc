# $NetBSD: Makefile,v 1.2 2015/12/05 21:25:58 adam Exp $

PKGNAME=	${PYPKGPREFIX}-yara-${YAVER}
CATEGORIES=	security python

COMMENT=	Yara python bindings

WRKSRC=		${WRKDIR}/yara-${YAVER}/yara-python

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=   33 34 35

.include "../../security/yara/Makefile.common"
.include "../../security/yara/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
