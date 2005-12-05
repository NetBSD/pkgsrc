# $NetBSD: Makefile,v 1.6 2005/12/05 20:50:07 rillig Exp $
#

DISTNAME=	gadfly-1.0.0
PKGNAME=	${PYPKGPREFIX}-kjbuckets-2.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gadfly/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/aaron_watters/kjbuckets/
COMMENT=	Fast set, graph and mapping operations

EXTRACT_ELEMENTS=	${DISTNAME}/kjbuckets
EXTRACT_ELEMENTS+=	${DISTNAME}/doc/kjbuckets.txt
WRKSRC=			${WRKDIR}/${DISTNAME}/kjbuckets


PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}

KJBDOCDIR=	${PREFIX}/share/doc/${PYPKGPREFIX}-kjbuckets

post-install:
	${INSTALL_DATA_DIR} ${KJBDOCDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/kjbuckets.txt ${KJBDOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
