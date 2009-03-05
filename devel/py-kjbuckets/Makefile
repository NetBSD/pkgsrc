# $NetBSD: Makefile,v 1.10 2009/03/05 18:51:29 joerg Exp $
#

DISTNAME=	gadfly-1.0.0
PKGNAME=	${PYPKGPREFIX}-kjbuckets-2.2
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gadfly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/aaron_watters/kjbuckets/
COMMENT=	Fast set, graph and mapping operations

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_ELEMENTS=	${DISTNAME}/kjbuckets
EXTRACT_ELEMENTS+=	${DISTNAME}/doc/kjbuckets.txt
WRKSRC=			${WRKDIR}/${DISTNAME}/kjbuckets

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}

KJBDOCDIR=	${PREFIX}/share/doc/${PYPKGPREFIX}-kjbuckets

INSTALLATION_DIRS=	${KJBDOCDIR}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/kjbuckets.txt ${DESTDIR}${KJBDOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
