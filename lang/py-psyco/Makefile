# $NetBSD: Makefile,v 1.9 2006/02/05 23:09:47 joerg Exp $

DISTNAME=       psyco-1.4-src
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-src//}
PKGREVISION=     1
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
