# $NetBSD: Makefile,v 1.5 2001/07/17 02:56:44 dmcmahill Exp $
#

DISTNAME=		docs-${PKGVERSION}
PKGNAME=		geda-${DISTNAME}
WRKSRC=			${WRKDIR}/docs
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		HTML documentation for gEDA

CONFLICTS+=		gEDA<19991011

DIST_SUBDIR=		geda
PKGVERSION=		20010304

NO_PATCH=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES
USE_X11BASE=		YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gEDA
.for file in README fileformats.html keymapping.html symbols.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gEDA
.endfor

.include "../../mk/bsd.pkg.mk"
