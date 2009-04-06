# $NetBSD: Makefile,v 1.6 2009/04/06 09:28:25 is Exp $
#

DISTNAME=	pgf-1.10
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	print graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pgf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pgf.sourceforge.net/
COMMENT=	Graphic systems for TeX

DEPENDS=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

USE_TOOLS+=	pax
USE_DIRS+=	texmf-1.4

.include "../../print/teTeX/module.mk"

do-build:

do-install:
	cd ${WRKSRC}/context && \
		pax -pmap -rw pgf ${PKG_LOCALTEXMFPREFIX}/tex/context/
	cd ${WRKSRC}/doc/generic && \
		pax -pmap -rw pgf ${PKG_LOCALTEXMFPREFIX}/doc/generic/
	cd ${WRKSRC}/generic && \
		pax -pmap -rw pgf ${PKG_LOCALTEXMFPREFIX}/tex/generic/
	cd ${WRKSRC}/latex && \
		pax -pmap -rw pgf ${PKG_LOCALTEXMFPREFIX}/tex/latex/
	cd ${WRKSRC}/plain && \
		pax -pmap -rw pgf ${PKG_LOCALTEXMFPREFIX}/tex/plain/

.include "../../mk/bsd.pkg.mk"
