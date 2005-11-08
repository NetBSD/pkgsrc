# $NetBSD: Makefile,v 1.4 2005/11/08 21:17:36 tonio Exp $
#

DISTNAME=	IEEEtran-1.6c
PKGNAME=	tex-IEEEtran-1.6c
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/IEEEtran/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ieee.org/organizations/pubs/transactions/stylesheets.htm
COMMENT=	LaTeX class for IEEE journals and conferences

DIST_SUBDIR=	${DISTNAME}
DISTFILES= IEEEtran.cls IEEEtran_HOWTO.pdf README bare_conf.tex bare_jrnl.tex

EXTRACT_ONLY=	# nothing
NO_CONFIGURE=	yes
NO_BUILD=	yes

IEEETRANDIR=	${PKG_LOCALTEXMFPREFIX}/tex/latex/IEEEtran

do-install:
	${INSTALL_DATA_DIR} ${IEEETRANDIR}
	for f in ${DISTFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$f ${IEEETRANDIR}; \
	done

post-install:
	${LOCALBASE}/bin/texconfig rehash

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
