# $NetBSD: Makefile,v 1.4 2004/07/22 09:16:02 recht Exp $

DISTNAME=       psyco-1.2-src
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-src//}
CATEGORIES=     lang python
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=psyco/}

MAINTAINER=     dotz@irc.pl
HOMEPAGE=       http://psyco.sf.net/
COMMENT=        Python JIT and execution accelerator

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
USE_BUILDLINK3=	YES
PYDISTUTILSPKG=	YES
PYBINMODULE=	YES
PY_PATCHPLIST=	YES

ONLY_FOR_PLATFORM=		*-*-i386
PYTHON_VERSIONS_ACCEPTED=	23 23pth 22 22pth 21 21pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
