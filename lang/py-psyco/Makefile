# $NetBSD: Makefile,v 1.5 2005/01/23 20:41:46 recht Exp $

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
PYTHON_VERSIONS_ACCEPTED=	23 22 21

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
