# $NetBSD: Makefile,v 1.1.1.1 2007/06/03 08:59:02 jmmv Exp $

DISTNAME=	resume
PKGNAME=	tex-${DISTNAME}-20010823
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.ctan.org/tex-archive/macros/latex/contrib/resume/
COMMENT=	Resume document style

NO_BUILD=	yes
USE_DIRS+=	texmf-1.4

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/resume
	${INSTALL_DATA} ${WRKSRC}/res.cls \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/resume

.include "../../mk/bsd.pkg.mk"
