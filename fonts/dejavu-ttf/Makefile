# $NetBSD: Makefile,v 1.23 2016/07/31 12:09:59 mef Exp $

DISTNAME=	dejavu-fonts-ttf-2.37
PKGNAME=	${DISTNAME:S/fonts-//}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dejavu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://dejavu.sourceforge.net/
COMMENT=	DejaVu family of TrueType fonts
# LICENSE=	# complex of severals, see LICENSE file

NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF

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

INSTALLATION_DIRS=	share/fonts/X11/TTF ${DOCSDIR} ${FCEGDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/fontconfig/*.conf ${DESTDIR}${FCEGDIR}
.for docfile in AUTHORS BUGS LICENSE NEWS README.md
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
