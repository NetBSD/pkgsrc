# $NetBSD: Makefile,v 1.19 2006/05/13 03:44:24 minskim Exp $
#

NAME=		textpos
DISTNAME=	${NAME}
PKGNAME=	tex-${NAME}-1.2b
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/supported/${NAME}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=
COMMENT=	Absolute positioning of text on the LaTeX page

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${NAME}
DISTFILES=	textpos.ins LICENCE README textpos.dtx VERSION

# included in teTeX3
TEX_ACCEPTED=	teTeX2

NO_CONFIGURE=	yes
USE_DIRS+=	texmf-1.0

.include "../../mk/bsd.prefs.mk"

.if ${TEX_DEFAULT} == "teTeX3"
PKG_SKIP_REASON+=	"textpos is included in ${TEX_DEFAULT}."
.else
.include "../../print/teTeX/module.mk"
.endif

do-build:
	cd ${WRKSRC} && latex textpos.ins
	cd ${WRKSRC} && latex textpos.drv

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/textpos-example.tex \
		${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	for f in LICENCE README VERSION textpos.dvi; do \
		${INSTALL_DATA} ${WRKSRC}/$$f \
			${PREFIX}/share/doc/${PKGBASE}; done
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/textpos
	for f in textpos.sty textpos.dtx; do \
		${INSTALL_DATA} ${WRKSRC}/$$f \
			${PKG_LOCALTEXMFPREFIX}/tex/latex/textpos; done

.include "../../mk/bsd.pkg.mk"
