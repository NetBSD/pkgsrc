# $NetBSD: Makefile,v 1.11 2006/06/04 12:06:29 joerg Exp $

DISTNAME=       psyco-1.4-src
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-src//}
PKGREVISION=     1
CATEGORIES=     lang python
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=psyco/}

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=       http://psyco.sf.net/
COMMENT=        Python JIT and execution accelerator

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
PYDISTUTILSPKG=	YES
PYBINMODULE=	YES
PY_PATCHPLIST=	YES

ONLY_FOR_PLATFORM=		*-*-i386
PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
