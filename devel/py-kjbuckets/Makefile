# $NetBSD: Makefile,v 1.3 2004/04/27 03:09:58 snj Exp $
#

DISTNAME=	gadfly-1.0.0
PKGNAME=	${PYPKGPREFIX}-kjbuckets-2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gadfly/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/aaron_watters/kjbuckets/
COMMENT=	Fast set, graph and mapping operations

EXTRACT_ELEMENTS=	${DISTNAME}/kjbuckets
EXTRACT_ELEMENTS+=	${DISTNAME}/doc/kjbuckets.txt
WRKSRC=			${WRKDIR}/${DISTNAME}/kjbuckets

USE_BUILDLINK3=	yes

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

KJBDOCDIR=	${PREFIX}/share/doc/${PYPKGPREFIX}-kjbuckets

post-install:
	${INSTALL_DATA_DIR} ${KJBDOCDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/kjbuckets.txt ${KJBDOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
