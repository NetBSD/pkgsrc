# $NetBSD: Makefile,v 1.5 2019/12/06 19:32:24 markd Exp $

DISTNAME=	rsfs.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2009
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE:S/-doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-rsfs

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
