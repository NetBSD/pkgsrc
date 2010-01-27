# $NetBSD: Makefile,v 1.9 2010/01/27 16:31:20 joerg Exp $
#

DISTNAME=	pgf-2.00
PKGNAME=	tex-${DISTNAME}
CATEGORIES=	print graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pgf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pgf.sourceforge.net/
COMMENT=	Graphic systems for TeX

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

USE_TOOLS+=	pax

.include "../../print/teTeX/module.mk"

INSTALLATION_DIRS+=	${PKG_LOCALTEXMFPREFIX}/tex/context \
			${PKG_LOCALTEXMFPREFIX}/doc/generic/ \
			${PKG_LOCALTEXMFPREFIX}/tex/generic/ \
			${PKG_LOCALTEXMFPREFIX}/tex/latex/ \
			${PKG_LOCALTEXMFPREFIX}/tex/plain/

do-build:

do-install:
	cd ${WRKSRC}/context && \
		pax -pmap -rw pgf ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/context/
	cd ${WRKSRC}/doc/generic && \
		pax -pmap -rw pgf ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/doc/generic/
	cd ${WRKSRC}/generic && \
		pax -pmap -rw pgf ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/generic/
	cd ${WRKSRC}/latex && \
		pax -pmap -rw pgf ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/
	cd ${WRKSRC}/plain && \
		pax -pmap -rw pgf ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/plain/

.include "../../mk/bsd.pkg.mk"
