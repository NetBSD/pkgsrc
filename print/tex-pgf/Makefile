# $NetBSD: Makefile,v 1.3 2008/04/01 01:36:32 tnn Exp $
#

DISTNAME=	pgf-1.10
PKGNAME=	tex-${DISTNAME}
CATEGORIES=	print graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pgf/}
PKGREVISION=	1
DEPENDS=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pgf.sourceforge.net/
COMMENT=	Graphic systems for TeX

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
