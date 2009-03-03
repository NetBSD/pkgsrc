# $NetBSD: Makefile,v 1.2 2009/03/03 15:22:07 jmmv Exp $

DISTNAME=	resume
PKGNAME=	tex-${DISTNAME}-20010823
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.ctan.org/tex-archive/macros/latex/contrib/resume/
COMMENT=	Resume document style

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
USE_DIRS+=	texmf-1.4

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/resume
	${INSTALL_DATA} ${WRKSRC}/res.cls \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/resume

.include "../../mk/bsd.pkg.mk"
