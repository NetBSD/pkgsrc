# $NetBSD: Makefile,v 1.3 2009/07/22 09:01:45 wiz Exp $

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

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/resume
	${INSTALL_DATA} ${WRKSRC}/res.cls \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/resume

.include "../../mk/bsd.pkg.mk"
