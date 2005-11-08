# $NetBSD: Makefile,v 1.12 2005/11/08 21:45:01 tonio Exp $
#

NAME=		textpos
DISTNAME=	${NAME}
PKGNAME=	tex-${NAME}-1.2b
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/supported/${NAME}/}

MAINTAINER=	tech-pkg@NetBSD.org
# HOMEPAGE=
COMMENT=	Absolute positioning of text on the LaTeX page

WRKSRC=		${WRKDIR}/${NAME}
DIST_SUBDIR=	${NAME}
DISTFILES=	textpos.ins LICENCE README textpos.dtx VERSION

# included in teTeX3
LATEX_ACCEPTED= teTeX1 teTeX2
CONFLICTS+=	teTeX-bin>=3.0

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-extract:

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/textpos
	for f in ${DISTFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$f \
			${PKG_LOCALTEXMFPREFIX}/tex/latex/textpos; \
	done

post-install:
	cd ${PKG_LOCALTEXMFPREFIX}/tex/latex/textpos; latex textpos.ins
	${LOCALBASE}/bin/texconfig rehash

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
