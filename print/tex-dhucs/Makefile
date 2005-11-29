# $NetBSD: Makefile,v 1.1.1.1 2005/11/29 22:37:39 minskim Exp $

DISTNAME=	dhucs-2.60cvs-20051117
PKGNAME=	tex-${DISTNAME:S/cvs-/./}
CATEGORIES=	print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/dhucs/current/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} tex-unttf-dhucs-20051115.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://faq.ktug.or.kr/faq/DHUcs
COMMENT=	LaTeX package to typeset Korean documents (UTF-8)

DEPENDS+=	tex-ucs>=20041710nb2:../../print/tex-ucs
DEPENDS+=	tex-unttf>=1.0.1.20051115:../../fonts/tex-unttf

SITES_tex-unttf-dhucs-20051115.tar.bz2= \
	http://home.bawi.org/~minskim/distfiles/

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

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
	extract_file=${_DISTDIR:Q}/tex-unttf-dhucs-20051115.tar.bz2; \
	cd ${PKG_LOCALTEXMFPREFIX}/tex; ${EXTRACT_CMD.tar.bz2}

.include "../../mk/bsd.pkg.mk"
