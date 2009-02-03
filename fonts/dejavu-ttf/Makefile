# $NetBSD: Makefile,v 1.11 2009/02/03 20:38:01 jakllsch Exp $
#

DISTNAME=	dejavu-fonts-ttf-2.28
PKGNAME=        ${DISTNAME:S/fonts-//}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dejavu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://dejavu.sourceforge.net/
COMMENT=	DejaVu family of TrueType fonts

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	pax

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF

EGDIR=		${PREFIX}/share/examples/dejavu-ttf
FCEGDIR=	${EGDIR}/fontconfig-conf.d
FCCFDIR=	${PKG_SYSCONFDIR}/fontconfig/conf.d

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

INSTALLATION_DIRS=	lib/X11/fonts/TTF share/doc/dejavu-ttf ${FCEGDIR}

do-install:
	cd ${WRKSRC}/ttf && pax -rw -pm *.ttf \
		${DESTDIR}${FONTS_DIRS.ttf}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS BUGS LICENSE NEWS README \
		${DESTDIR}${PREFIX}/share/doc/dejavu-ttf
	cd ${WRKSRC}/fontconfig && pax -rw -pm *.conf \
		${DESTDIR}${FCEGDIR}

.include "../../mk/bsd.pkg.mk"
