# $NetBSD: Makefile,v 1.3 2019/12/06 20:19:34 markd Exp $
# TeX Live Revision 17262

DISTNAME=	excludeonly
PKGNAME=	tex-${DISTNAME}-1.0

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX package to prevent files being \include-ed
LICENSE=	public-domain

CONFLICTS+=	tex-ltxmisc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
