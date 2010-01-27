# $NetBSD: Makefile,v 1.4 2010/01/27 16:14:26 joerg Exp $

DISTNAME=	fixme
PKGNAME=	tex-${DISTNAME}-3.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://tug.ctan.org/tex-archive/macros/latex/contrib/fixme/
COMMENT=	Insert "fixme" notes into draft documents

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	${PKGNAME}

.include "../../print/teTeX/module.mk"

INSTALLATION_DIRS+=	${PKG_LOCALTEXMFPREFIX}/doc/latex/fixme \
			${PKG_LOCALTEXMFPREFIX}/tex/latex/fixme

do-build:
	cd ${WRKSRC} && latex fixme.ins

do-install:
	${INSTALL_DATA} ${WRKSRC}/NEWS ${WRKSRC}/README ${WRKSRC}/fixme.pdf \
	    ${WRKSRC}/fixme.el ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/doc/latex/fixme
	${INSTALL_DATA} ${WRKSRC}/fixme.sty \
	    ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/fixme

.include "../../mk/bsd.pkg.mk"
