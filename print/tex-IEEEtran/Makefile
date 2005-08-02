# $NetBSD: Makefile,v 1.3 2005/08/02 14:48:43 drochner Exp $
#

DISTNAME=	IEEEtran-1.6b
PKGNAME=	tex-IEEEtran-1.6b
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/IEEEtran/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ieee.org/organizations/pubs/transactions/stylesheets.htm
COMMENT=	LaTeX class for IEEE journals and conferences

DIST_SUBDIR=	${DISTNAME}
DISTFILES= IEEEtran.cls IEEEtran_HOWTO.pdf README bare_conf.tex bare_jrnl.tex

DEPENDS+=       teTeX-bin-[0-9]*:../../print/teTeX-bin

EXTRACT_ONLY=	# nothing
NO_CONFIGURE=	yes
NO_BUILD=	yes

IEEETRANDIR=	${PREFIX}/share/texmf/tex/latex/IEEEtran

do-install:
	${INSTALL_DATA_DIR} ${IEEETRANDIR}
	for f in ${DISTFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$f ${IEEETRANDIR}; \
	done

post-install:
	${LOCALBASE}/bin/texconfig rehash

.include "../../mk/bsd.pkg.mk"
