# $NetBSD: Makefile,v 1.1.1.1 2002/04/17 20:47:20 tsarna Exp $

DISTNAME=	Plex1.1.2
PKGNAME=	${PYPKGPREFIX}-plex-1.1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/~greg/python/Plex/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.cosc.canterbury.ac.nz/~greg/python/Plex/
COMMENT=	Lexical analysis module for Python

WRKSRC=		${WRKDIR}

pre-configure:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}

PYDISTUTILSPKG= # defined

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
