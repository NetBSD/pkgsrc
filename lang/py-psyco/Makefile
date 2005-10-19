# $NetBSD: Makefile,v 1.8 2005/10/19 01:33:16 wiz Exp $

DISTNAME=       psyco-1.4-src
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-src//}
CATEGORIES=     lang python
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=psyco/}

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=       http://psyco.sf.net/
COMMENT=        Python JIT and execution accelerator

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
PYDISTUTILSPKG=	YES
PYBINMODULE=	YES
PY_PATCHPLIST=	YES

ONLY_FOR_PLATFORM=		*-*-i386
PYTHON_VERSIONS_ACCEPTED=	24 23 22 21

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
