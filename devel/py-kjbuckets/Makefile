# $NetBSD: Makefile,v 1.20 2019/04/26 14:12:36 maya Exp $

DISTNAME=	gadfly-1.0.0
PKGNAME=	${PYPKGPREFIX}-kjbuckets-2.2
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gadfly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gadfly.sourceforge.net/kjbuckets.html
COMMENT=	Fast set, graph and mapping operations

EXTRACT_ELEMENTS=	${DISTNAME}/kjbuckets
EXTRACT_ELEMENTS+=	${DISTNAME}/doc/kjbuckets.txt
WRKSRC=			${WRKDIR}/${DISTNAME}/kjbuckets

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}
PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 1.0.0 resp. 2.2

KJBDOCDIR=	${PREFIX}/share/doc/${PYPKGPREFIX}-kjbuckets

EGG_NAME=	kjbuckets-${PKGVERSION_NOREV}

INSTALLATION_DIRS=	${KJBDOCDIR}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/kjbuckets.txt ${DESTDIR}${KJBDOCDIR}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
