# $NetBSD: Makefile,v 1.1.1.1 2003/03/13 10:47:02 mjl Exp $
#

DISTNAME=	textpos
PKGNAME=	tex-${DISTNAME}-1.2b
# PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/supported/}

MAINTAINER=	packages@netbsd.org
# HOMEPAGE=	
COMMENT=	absolute positioning of text on the LaTeX page

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin

NO_CONFIGURE=	yes
NO_PATCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/tex/latex/textpos
	for f in LICENCE README VERSION textpos.dtx textpos.ins; do \
		${INSTALL_DATA} ${WRKSRC}/$$f \
			${PREFIX}/share/texmf/tex/latex/textpos; \
	done

post-install:
	cd ${PREFIX}/share/texmf/tex/latex/textpos; latex textpos.ins
	${LOCALBASE}/bin/texconfig rehash

.include "../../mk/bsd.pkg.mk"
