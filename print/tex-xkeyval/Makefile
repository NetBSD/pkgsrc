# $NetBSD: Makefile,v 1.4 2010/09/14 20:50:12 minskim Exp $

DISTNAME=	xkeyval
PKGNAME=	tex-${DISTNAME}-2.6a
TEXLIVE_REV=	15878

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Macros for setting keys and class or package options

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
