# $NetBSD: Makefile,v 1.4 2019/12/06 20:23:28 markd Exp $
# TeX Live Revision 15878

DISTNAME=	texpower
PKGNAME=	tex-${DISTNAME}-0.2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Create dynamic online presentations with LaTeX
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-tpslifonts-[0-9]*:../../print/tex-tpslifonts

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
