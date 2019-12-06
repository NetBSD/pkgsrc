# $NetBSD: Makefile,v 1.4 2019/12/06 20:23:43 markd Exp $
# TeX Live Revision 15878

DISTNAME=	wallpaper
PKGNAME=	tex-${DISTNAME}-1.10
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easy addition of wallpapers (background images) to LaTeX documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-eso-pic-[0-9]*:../../print/tex-eso-pic

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
