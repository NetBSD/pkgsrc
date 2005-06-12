# $NetBSD: Makefile,v 1.7 2005/06/12 08:52:54 taya Exp $

.include	"../../inputmethod/anthy/Makefile.common"

PKGREVISION=	1
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
PKG_OPTIONS_LEGACY_VARS+=	USE_2CH_DICT:2ch_dict
PKG_OPTIONS_LEGACY_VARS+=	USE_OKINAWA_DICT:okinawa_dict

.include	"../../mk/bsd.options.mk"

###
### Optional dictionary support
###
.if !empty(PKG_OPTIONS:M2ch_dict)
DISTFILES+=	2ch.t
SITES_2ch.t+=	http://omaemona.sourceforge.net/packages/Zisyo/
.endif

.if !empty(PKG_OPTIONS:Mokinawa_dict)
DISTFILES+=			okinawa-20050607.t
SITES_okinawa-20050607.t+=	http://www.ofug.net/~yamajun/files/
.endif

post-patch:
.if !empty(PKG_OPTIONS:M2ch_dict)
	${CP} ${DISTDIR}/2ch.t ${WRKSRC}/mkanthydic
	@printf '/^EXTRA_DICS\ns/$$/ 2ch.t/\nwq\n' | \
		ed -s ${WRKSRC}/mkanthydic/Makefile.in
.endif
.if !empty(PKG_OPTIONS:Mokinawa_dict)
	${CP} ${DISTDIR}/okinawa-20050607.t ${WRKSRC}/mkanthydic
	@printf '/^EXTRA_DICS\ns/$$/ okinawa-20050607.t/\nwq\n' | \
		ed -s ${WRKSRC}/mkanthydic/Makefile.in
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/doc/DICUTIL ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/doc/ELISP ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/doc/GUIDE.english ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/anthy

.include "../../mk/bsd.pkg.mk"
