# $NetBSD: Makefile,v 1.4 2011/10/18 20:46:07 minskim Exp $

DISTNAME=	resume
PKGNAME=	tex-${DISTNAME}-20010823
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.ctan.org/tex-archive/macros/latex/contrib/resume/
COMMENT=	Resume document style

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

INSTALLATION_DIRS=	share/texmf-dist/tex/latex/resume

.include "../../print/kpathsea/texmf.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/res.cls \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/resume/

.include "../../mk/bsd.pkg.mk"
