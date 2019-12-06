# $NetBSD: Makefile,v 1.3 2019/12/06 20:23:27 markd Exp $

DISTNAME=	texdoctk
PKGNAME=	tex-${DISTNAME}-0.6.0.50602
TEXLIVE_REV=	50602

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/texdoctk
COMMENT=	Easy access to package documentation
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	p5-Tk-[0-9]*:../../x11/p5-Tk

REPLACE_PERL=	bin/texdoctk

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texdoctk/texdoctk.pl \
		${WRKSRC}/bin/texdoctk
	${RMDIR} ${WRKSRC}/texmf-dist/scripts/texdoctk

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
