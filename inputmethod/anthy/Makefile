# $NetBSD: Makefile,v 1.10 2006/01/23 23:08:47 wiz Exp $

.include	"../../inputmethod/anthy/Makefile.common"

EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	taya@NetBSD.org
COMMENT=	Kana Kanji conversion system

USE_LIBTOOL=		yes
USE_LANGUAGES=		c
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		EMACS=no

PKGCONFIG_OVERRIDE+=	anthy.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.anthy
PKG_SUPPORTED_OPTIONS=	2ch_dict okinawa_dict

.include	"../../mk/bsd.options.mk"

###
### Optional dictionary support
###
.if !empty(PKG_OPTIONS:M2ch_dict)
DISTFILES+=	2ch.t
SITES_2ch.t+=	http://omaemona.sourceforge.net/packages/Zisyo/
.endif

.if !empty(PKG_OPTIONS:Mokinawa_dict)
OKIDIC_VERSION=			okinawa-20051104
DISTFILES+=			${OKIDIC_VERSION}.tar.gz
EXTRACT_ONLY+=			${OKIDIC_VERSION}.tar.gz
SITES_${OKIDIC_VERSION}.tar.gz+=	http://www.ofug.net/~yamajun/files/
.endif

post-patch:
.if !empty(PKG_OPTIONS:M2ch_dict)
	${CP} ${DISTDIR}/2ch.t ${WRKSRC}/mkanthydic
	@${PRINTF} "/read @top_srcdir@\\\\/mkanthydic\\\\/placename.t\na\nread @top_srcdir@/mkanthydic/2ch.t\n.\nw\n" | \
	ed -s ${WRKSRC}/mkanthydic/dict.args.in
.endif
.if !empty(PKG_OPTIONS:Mokinawa_dict)
	${CP} ${WRKDIR}/${OKIDIC_VERSION}/okinawa.t ${WRKSRC}/mkanthydic
	@${PRINTF} "/read @top_srcdir@\\\\/mkanthydic\\\\/placename.t\na\nread @top_srcdir@/mkanthydic/okinawa.t\n.\nw\n" | \
	ed -s ${WRKSRC}/mkanthydic/dict.args.in
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/doc/DICUTIL ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/doc/ELISP ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/doc/GUIDE.english ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/README.en ${PREFIX}/share/doc/anthy

.include "../../mk/bsd.pkg.mk"
