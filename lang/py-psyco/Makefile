# $NetBSD: Makefile,v 1.1.1.1 2003/10/01 22:39:06 recht Exp $

DISTNAME=       psyco-1.1.1-src
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-src//}
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=     lang
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=psyco/}

MAINTAINER=     dotz@irc.pl
HOMEPAGE=       http://psyco.sf.net/
COMMENT=        Python JIT and execution accelerator

USE_BUILDLINK2=	YES
PYDISTUTILSPKG=	YES
PYBINMODULE=	YES
PY_PATCHPLIST=	YES

ONLY_FOR_PLATFORM=		*-*-i386
PYTHON_VERSIONS_ACCEPTED=	23 23pth 22 22pth 21 21pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
