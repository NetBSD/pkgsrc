# $NetBSD: Makefile,v 1.5 2003/07/17 22:52:43 grant Exp $
#

NAME=		textpos
DISTNAME=	${NAME}
PKGNAME=	tex-${NAME}-1.2b
# PKGREVISION=	1
WRKSRC=		${WRKDIR}/${NAME}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/supported/${NAME}/}

MAINTAINER=	tech-pkg@NetBSD.org
# HOMEPAGE=	
COMMENT=	absolute positioning of text on the LaTeX page

DIST_SUBDIR=	${NAME}
DISTFILES=	textpos.ins LICENCE README textpos.dtx VERSION

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-extract:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/tex/latex/textpos
	for f in ${DISTFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$f \
			${PREFIX}/share/texmf/tex/latex/textpos; \
	done

post-install:
	cd ${PREFIX}/share/texmf/tex/latex/textpos; latex textpos.ins
	${LOCALBASE}/bin/texconfig rehash

.include "../../mk/bsd.pkg.mk"
