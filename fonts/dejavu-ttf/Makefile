# $NetBSD: Makefile,v 1.25 2021/07/23 10:20:30 hauke Exp $

DISTNAME=	dejavu-fonts-ttf-2.37
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/fonts-//}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dejavu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jakllsch@NetBSD.org
#HOMEPAGE=	http://dejavu.sourceforge.net/
COMMENT=	DejaVu family of TrueType fonts
# LICENSE=	# complex of severals, see LICENSE file

NO_CONFIGURE=	yes
NO_BUILD=	yes

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
TTFDIR=		${PREFIX}/share/fonts/X11/TTF
FCEGDIR=	${EGDIR}/fontconfig-conf.d
FCCFDIR=	${PKG_SYSCONFDIR}/fontconfig/conf.d
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

PKG_OPTIONS_VAR=	PKG_OPTIONS.dejavu-fonts-ttf
PKG_SUPPORTED_OPTIONS+=	x11
PKG_SUGGESTED_OPTIONS+=	x11

.include "../../mk/bsd.options.mk"

# Only attempt to register fonts if we have X11 support (mkfontdir)
.if !empty(PKG_OPTIONS:Mx11)
FONTS_DIRS.ttf=	${TTFDIR}
.endif

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
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf ${DESTDIR}${TTFDIR}
	${INSTALL_DATA} ${WRKSRC}/fontconfig/*.conf ${DESTDIR}${FCEGDIR}
.for docfile in AUTHORS BUGS LICENSE NEWS README.md
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
