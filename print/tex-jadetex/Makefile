# $NetBSD: Makefile,v 1.28 2010/01/28 09:26:46 wiz Exp $
#

DISTNAME=	jadetex-3.13
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jadetex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jadetex.sourceforge.net/
COMMENT=	Process tex files produced by the TeX backend of Jade

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX3-bin

BUILD_TARGET=	default
MAKE_ENV+=	TEX=${TEX:Q}

EVAL_PREFIX+=	TETEX_BIN_PREFIX=teTeX-bin
FILES_SUBST+=	TEX=${TETEX_BIN_PREFIX:Q}/bin/etex
FILES_SUBST+=	PDFTEX=${TETEX_BIN_PREFIX:Q}/bin/pdftex

TEX=	${LOCALBASE}/bin/etex
PDFTEX=	${LOCALBASE}/bin/pdftex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist
TEX_CONFIG_NAMES=	jadetex

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/jadetex \
			share/texmf/web2c \
			share/texmf-dist/tex/jadetex/base \
			share/texmf-dist/tex/jadetex/config

.include "../../print/kpathsea/texmf.mk"

do-install:
	${RM} -f ${PREFIX}/bin/jadetex
	${LN} -s ${TEX} ${PREFIX}/bin/jadetex
	${RM} -f ${PREFIX}/bin/pdfjadetex
	${LN} -s ${PDFTEX} ${PREFIX}/bin/pdfjadetex
	${INSTALL_MAN} ${WRKSRC}/jadetex.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/pdfjadetex.1 ${PREFIX}/${PKGMANDIR}/man1
	for i in ${WRKSRC}/doc/* ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/jadetex; \
	done
	${INSTALL_DATA} ${FILESDIR}/texmf.jadetex.cnf \
		${PREFIX}/share/texmf/web2c
.for f in dsssl.def jadetex.ltx uentities.sty ut1omlgc.fd
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${PREFIX}/share/texmf-dist/tex/jadetex/base
.endfor
.for f in jadetex.ini pdfjadetex.ini mlnames.sty unicode.sty dummyels.sty \
		ucharacters.sty
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${PREFIX}/share/texmf-dist/tex/jadetex/config
.endfor

.include "../../mk/bsd.pkg.mk"
