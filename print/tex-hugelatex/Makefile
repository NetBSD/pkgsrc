# $NetBSD: Makefile,v 1.23 2009/04/09 00:48:15 joerg Exp $
#

DISTNAME=	hugelatex-2.0
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	print
MASTER_SITES=	# none
DISTFILES=	# nada

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	LaTeX format files with large limits

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX3-bin

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEX_CONFIG_NAMES=	hugelatex

EVAL_PREFIX+=	TETEX_BIN_PREFIX=teTeX-bin
FILES_SUBST+=	LATEX=${TETEX_BIN_PREFIX:Q}/bin/latex

CHECK_FILES_SKIP+=	${PKG_TEXMFPREFIX}/web2c/hugelatex.fmt
CHECK_FILES_SKIP+=	${PKG_TEXMFPREFIX}/web2c/hugelatex.log

.include "../../print/kpathsea/texmf.mk"

do-install:
	${LN} -sf latex ${PREFIX}/bin/hugelatex
	${INSTALL_DATA} ${FILESDIR}/texmf.hugelatex.cnf \
		${PREFIX}/share/texmf/web2c/texmf.hugelatex.cnf

.include "../../mk/bsd.pkg.mk"
