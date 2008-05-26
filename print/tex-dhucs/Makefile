# $NetBSD: Makefile,v 1.13 2008/05/26 02:13:23 joerg Exp $

DISTNAME=	dhucs-3.2.2-20070507
PKGNAME=	tex-${DISTNAME:C/-[0-9]+$//}
CATEGORIES=	print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/hangul-ucs/current/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} fonts-unttf-20070507.tar.gz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://faq.ktug.or.kr/faq/Hangul-ucs
COMMENT=	LaTeX package to typeset Korean documents (UTF-8)

DEPENDS+=	tex-ucs>=20041710nb2:../../print/tex-ucs
DEPENDS+=	tex-unttf>=1.0.1.20070507:../../fonts/tex-unttf

SITES.fonts-unttf-20070507.tar.gz= \
	http://ftp.ktug.or.kr/KTUG/hangul-ucs/fonts/

WRKSRC=		${WRKDIR}/dhucs
NO_BUILD=	yes
USE_DIRS+=	texmf-1.0
USE_TOOLS+=	bzcat pax perl:run

REPLACE_PERL+=	script/makeindex-dhucs.pl

INSTALLATION_DIRS=	bin

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/script/makeindex-dhucs.pl \
		${PREFIX}/bin/makeindex-dhucs
	${INSTALL_DATA} ${WRKSRC}/makeindex/dhucs.ist \
		${PKG_LOCALTEXMFPREFIX}/makeindex/
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs
	cd ${WRKSRC}/tex-latex-dhucs && pax -rwppm . \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs/
	find ${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs \
		-type d -exec chmod ${PKGDIRMODE} {} \;
	find ${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs \
		-type f -exec chmod ${SHAREMODE} {} \;
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/ucsplain
	${INSTALL_DATA} ${WRKSRC}/ucsplain/*.* ${PKG_LOCALTEXMFPREFIX}/tex/ucsplain
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs/unttf
	${INSTALL_DATA} ${WRKDIR}/fonts-unttf/tex/latex/dhucs/unttf/*.* \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs/unttf/

.include "../../mk/bsd.pkg.mk"
