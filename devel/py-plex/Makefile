# $NetBSD: Makefile,v 1.3 2002/10/24 12:37:48 drochner Exp $

DISTNAME=	Plex-1.1.4
PKGNAME=	${PYPKGPREFIX}-plex-1.1.4
CATEGORIES=	devel
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/~greg/python/Plex/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.cosc.canterbury.ac.nz/~greg/python/Plex/
COMMENT=	Lexical analysis module for Python

pre-configure:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}

PYDISTUTILSPKG= # defined

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
