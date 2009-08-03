# $NetBSD: Makefile,v 1.15 2009/08/03 15:37:41 joerg Exp $

DISTNAME=	dhucs-3.2.2-20070507
PKGNAME=	tex-${DISTNAME:C/-[0-9]+$//}
CATEGORIES=	print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/hangul-ucs/current/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} fonts-unttf-20070507.tar.gz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://faq.ktug.or.kr/faq/Hangul-ucs
COMMENT=	LaTeX package to typeset Korean documents (UTF-8)

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	tex-ucs>=20041710nb2:../../print/tex-ucs
DEPENDS+=	tex-unttf>=1.0.1.20070507:../../fonts/tex-unttf

SITES.fonts-unttf-20070507.tar.gz= \
	http://ftp.ktug.or.kr/KTUG/hangul-ucs/fonts/

WRKSRC=		${WRKDIR}/dhucs
NO_BUILD=	yes
USE_TOOLS+=	bzcat pax perl:run

REPLACE_PERL+=	script/makeindex-dhucs.pl

INSTALLATION_DIRS=	bin ${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs/unttf \
	${PKG_LOCALTEXMFPREFIX}/makeindex \
	${PKG_LOCALTEXMFPREFIX}/tex/ucsplain

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/script/makeindex-dhucs.pl \
		${DESTDIR}${PREFIX}/bin/makeindex-dhucs
	${INSTALL_DATA} ${WRKSRC}/makeindex/dhucs.ist \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/makeindex/
	cd ${WRKSRC}/tex-latex-dhucs && pax -rwppm . \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs/
	find ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs \
		-type d -exec chmod ${PKGDIRMODE} {} \;
	find ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs \
		-type f -exec chmod ${SHAREMODE} {} \;
	${INSTALL_DATA_DIR} 
	${INSTALL_DATA} ${WRKSRC}/ucsplain/*.* ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/ucsplain
	${INSTALL_DATA_DIR} 
	${INSTALL_DATA} ${WRKDIR}/fonts-unttf/tex/latex/dhucs/unttf/*.* \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs/unttf/

.include "../../mk/bsd.pkg.mk"
