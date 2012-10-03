# $NetBSD: Makefile,v 1.2 2012/10/03 18:28:27 asau Exp $

DISTNAME=		lohit-fonts-2.3.1
CATEGORIES=		fonts
MASTER_SITES=		http://rbhalera.fedorapeople.org/released/lohit/
MASTER_SITES+=		${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://fedorahosted.org/lohit
COMMENT=		Free fonts for Indian languages

USE_X11BASE=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

FONTDIR=		${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${FONTDIR}

INSTALLATION_DIRS=	lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/bengali/lohit_bn.ttf	${DESTDIR}${FONTDIR}/
	${INSTALL_DATA} ${WRKSRC}/gujarati/lohit_gu.ttf	${DESTDIR}${FONTDIR}/
	${INSTALL_DATA} ${WRKSRC}/hindi/lohit_hi.ttf	${DESTDIR}${FONTDIR}/
	${INSTALL_DATA} ${WRKSRC}/kannada/lohit_kn.ttf	${DESTDIR}${FONTDIR}/
	${INSTALL_DATA} ${WRKSRC}/kashmiri/lohit_ks.ttf	${DESTDIR}${FONTDIR}/
	${INSTALL_DATA} ${WRKSRC}/konkani/lohit_kok.ttf	${DESTDIR}${FONTDIR}/
	${INSTALL_DATA} ${WRKSRC}/maithili/lohit_mai.ttf	${DESTDIR}${FONTDIR}/
	${INSTALL_DATA} ${WRKSRC}/malayalam/lohit_ml.ttf	${DESTDIR}${FONTDIR}/
	${INSTALL_DATA} ${WRKSRC}/marathi/lohit_mr.ttf	${DESTDIR}${FONTDIR}/
	${INSTALL_DATA} ${WRKSRC}/nepali/lohit_ne.ttf	${DESTDIR}${FONTDIR}/
	${INSTALL_DATA} ${WRKSRC}/oriya/lohit_or.ttf	${DESTDIR}${FONTDIR}/
	${INSTALL_DATA} ${WRKSRC}/punjabi/lohit_pa.ttf	${DESTDIR}${FONTDIR}/
	${INSTALL_DATA} ${WRKSRC}/sindhi/lohit_sd.ttf	${DESTDIR}${FONTDIR}/
	${INSTALL_DATA} ${WRKSRC}/tamil/lohit_ta.ttf	${DESTDIR}${FONTDIR}/
	${INSTALL_DATA} ${WRKSRC}/telugu/lohit_te.ttf	${DESTDIR}${FONTDIR}/

.include "../../mk/bsd.pkg.mk"
