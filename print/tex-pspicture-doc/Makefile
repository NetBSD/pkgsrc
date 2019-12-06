# $NetBSD: Makefile,v 1.4 2019/12/06 20:23:08 markd Exp $

DISTNAME=	pspicture.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2009
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE:S/-doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-pspicture
LICENSE=	lppl-1.3c

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
