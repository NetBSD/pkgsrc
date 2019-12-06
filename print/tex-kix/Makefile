# $NetBSD: Makefile,v 1.5 2019/12/06 20:21:46 markd Exp $

DISTNAME=	kix
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	21606

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Typeset KIX codes
LICENSE=	lppl-1.0

CONFLICTS+=	tex-ltxmisc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
