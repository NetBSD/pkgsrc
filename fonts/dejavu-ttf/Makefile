# $NetBSD: Makefile,v 1.19 2012/10/03 18:28:18 asau Exp $
#

DISTNAME=	dejavu-fonts-ttf-2.33
PKGNAME=	${DISTNAME:S/fonts-//}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dejavu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://dejavu.sourceforge.net/
COMMENT=	DejaVu family of TrueType fonts

NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
FCEGDIR=	${EGDIR}/fontconfig-conf.d
FCCFDIR=	${PKG_SYSCONFDIR}/fontconfig/conf.d
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

MAKE_DIRS+=	${FCCFDIR}

CONF_FILES=	${FCEGDIR}/20-unhint-small-dejavu-sans-mono.conf \
		${FCCFDIR}/20-unhint-small-dejavu-sans-mono.conf
CONF_FILES+=	${FCEGDIR}/20-unhint-small-dejavu-sans.conf \
		${FCCFDIR}/20-unhint-small-dejavu-sans.conf
CONF_FILES+=	${FCEGDIR}/20-unhint-small-dejavu-serif.conf \
		${FCCFDIR}/20-unhint-small-dejavu-serif.conf

CONF_FILES+=	${FCEGDIR}/57-dejavu-sans-mono.conf \
		${FCCFDIR}/57-dejavu-sans-mono.conf
CONF_FILES+=	${FCEGDIR}/57-dejavu-sans.conf \
		${FCCFDIR}/57-dejavu-sans.conf
CONF_FILES+=	${FCEGDIR}/57-dejavu-serif.conf \
		${FCCFDIR}/57-dejavu-serif.conf

REQD_DIRS=	${EGDIR}
REQD_DIRS+=	${FCEGDIR}

INSTALLATION_DIRS=	lib/X11/fonts/TTF ${DOCSDIR} ${FCEGDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/fontconfig/*.conf ${DESTDIR}${FCEGDIR}
.for docfile in AUTHORS BUGS LICENSE NEWS README
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
