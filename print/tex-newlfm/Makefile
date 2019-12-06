# $NetBSD: Makefile,v 1.2 2019/12/06 20:22:53 markd Exp $

DISTNAME=	newlfm
PKGNAME=	tex-${DISTNAME}-9.4
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/newlfm
COMMENT=	Write letters, facsimiles, and memos
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-envlab-[0-9]*:../../print/tex-envlab
DEPENDS+=	tex-eso-pic-[0-9]*:../../print/tex-eso-pic
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-mdwtools-[0-9]*:../../print/tex-mdwtools
DEPENDS+=	tex-rotating-[0-9]*:../../print/tex-rotating
DEPENDS+=	tex-setspace-[0-9]*:../../print/tex-setspace
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
