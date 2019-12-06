# $NetBSD: Makefile,v 1.2 2019/12/06 20:23:23 markd Exp $

DISTNAME=	svninfo
PKGNAME=	tex-${DISTNAME}-0.7.4
TEXLIVE_REV=	17554

MAINTAINER=	cfuhrman@panix.com
COMMENT=	Typeset Subversion keywords
LICENSE=	lppl-1.3c

DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
