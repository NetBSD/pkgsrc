# $NetBSD: Makefile,v 1.5.2.1 2002/06/23 18:39:48 jlam Exp $
#

DISTNAME=		geda-docs-${PKGVERSION}
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
PKGVERSION=		20020209

NO_PATCH=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES
USE_X11BASE=		YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gEDA
.for file in README attributes.txt hooks_and_scheme.txt keymapping.tex \
symbols.html README.keymapping fileformats.html keymapping.html \
netattrib.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gEDA
.endfor

.include "../../mk/bsd.pkg.mk"
