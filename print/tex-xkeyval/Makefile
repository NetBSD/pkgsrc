# $NetBSD: Makefile,v 1.6 2015/04/25 05:28:37 markd Exp $

DISTNAME=	xkeyval
PKGNAME=	tex-${DISTNAME}-2.7a
TEXLIVE_REV=	35741

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Macros for setting keys and class or package options
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
