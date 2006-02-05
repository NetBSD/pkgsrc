# $NetBSD: Makefile,v 1.3 2006/02/05 23:10:40 joerg Exp $

DISTNAME=	dhucs-2.60cvs-20051222
PKGNAME=	tex-${DISTNAME:S/cvs-/./}
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/hangul-ucs/current/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} fonts-unttf-20051219.tar.gz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://faq.ktug.or.kr/faq/DHUcs
COMMENT=	LaTeX package to typeset Korean documents (UTF-8)

DEPENDS+=	tex-ucs>=20041710nb2:../../print/tex-ucs
DEPENDS+=	tex-unttf>=1.0.1.20051219:../../fonts/tex-unttf

SITES_tex-unttf-dhucs-20051219.tar.bz2= \
	http://ftp.ktug.or.kr/KTUG/hangul-ucs/fonts/

WRKSRC=		${WRKDIR}/dhucs
NO_BUILD=	yes
USE_TOOLS+=	bzcat perl:run

REPLACE_PERL=	script/makeindex-dhucs.pl

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
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs/unttf
	${INSTALL_DATA} ${WRKDIR}/fonts-unttf/tex/latex/dhucs/unttf/*.* \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/dhucs/unttf/

.include "../../mk/bsd.pkg.mk"
