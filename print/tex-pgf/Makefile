# $NetBSD: Makefile,v 1.4 2008/04/09 19:34:41 wiz Exp $
#

DISTNAME=	pgf-1.10
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	print graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pgf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pgf.sourceforge.net/
COMMENT=	Graphic systems for TeX

DEPENDS=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

USE_DIRS+=	texmf-1.4

.include "../../print/teTeX/module.mk"

do-build:

do-install:
	cd ${WRKSRC}/context && \
		pax -ppa -rw pgf ${PKG_LOCALTEXMFPREFIX}/tex/context/
	cd ${WRKSRC}/doc/generic && \
		pax -ppa -rw pgf ${PKG_LOCALTEXMFPREFIX}/doc/generic/
	cd ${WRKSRC}/generic && \
		pax -ppa -rw pgf ${PKG_LOCALTEXMFPREFIX}/tex/generic/
	cd ${WRKSRC}/latex && \
		pax -ppa -rw pgf ${PKG_LOCALTEXMFPREFIX}/tex/latex/
	cd ${WRKSRC}/plain && \
		pax -ppa -rw pgf ${PKG_LOCALTEXMFPREFIX}/tex/plain/

.include "../../mk/bsd.pkg.mk"
