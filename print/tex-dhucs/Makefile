# $NetBSD: Makefile,v 1.9 2006/05/13 05:03:54 minskim Exp $

DISTNAME=	dhucs-3.0.0cvs-20060427
PKGNAME=	tex-${DISTNAME:C/cvs-.*//}
CATEGORIES=	print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/hangul-ucs/current/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} fonts-unttf-20060215.tar.gz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://faq.ktug.or.kr/faq/Hangul-ucs
COMMENT=	LaTeX package to typeset Korean documents (UTF-8)

DEPENDS+=	tex-ucs>=20041710nb2:../../print/tex-ucs
DEPENDS+=	tex-unttf>=1.0.1.20060215:../../fonts/tex-unttf

SITES.fonts-unttf-20060215.tar.gz= \
	http://ftp.ktug.or.kr/KTUG/hangul-ucs/fonts/

WRKSRC=		${WRKDIR}/dhucs
NO_BUILD=	yes
USE_DIRS+=	texmf-1.0
USE_TOOLS+=	bzcat perl:run

REPLACE_PERL+=	script/makeindex-dhucs.pl

INSTALLATION_DIRS=	bin

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/script/makeindex-dhucs.pl \
		${PREFIX}/bin/makeindex-dhucs
	${INSTALL_DATA} ${WRKSRC}/makeindex/dhucs.ist \
		${PKG_LOCALTEXMFPREFIX}/makeindex/
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs
	${INSTALL_DATA} ${WRKSRC}/tex-latex-dhucs/*.* \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs/
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs/contrib
	${INSTALL_DATA} ${WRKSRC}/tex-latex-dhucs/contrib/*.* \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs/contrib
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/ucsplain
	${INSTALL_DATA} ${WRKSRC}/ucsplain/*.* ${PKG_LOCALTEXMFPREFIX}/tex/ucsplain
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs/unttf
	${INSTALL_DATA} ${WRKDIR}/fonts-unttf/tex/latex/dhucs/unttf/*.* \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs/unttf/

.include "../../mk/bsd.pkg.mk"
