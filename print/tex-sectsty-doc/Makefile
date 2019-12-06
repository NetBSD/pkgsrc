# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:14 markd Exp $

DISTNAME=	sectsty.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.0.2
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE:S/-doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-sectsty
LICENSE=	lppl-1.3c

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
