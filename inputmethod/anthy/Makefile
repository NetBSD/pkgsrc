# $NetBSD: Makefile,v 1.3 2005/03/03 15:34:08 taya Exp $

.include	"../../inputmethod/anthy/Makefile.common"

EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	taya@NetBSD.org
COMMENT=	Kana Kanji conversion system

USE_LIBTOOL=		yes
USE_LANGUAGES=		c
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		EMACS=no

PKGCONFIG_OVERRIDE+=	anthy.pc.in

# Global and legacy options
.if defined(USE_2CH_DICT) && !empty(USE_2CH_DICT:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	2ch_dict
.endif

.if defined(USE_OKINAWA_DICT) && !empty(USE_OKINAWA_DICT:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	okinawa_dict
.endif

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
DISTFILES+=			okinawa-20041220.t
SITES_okinawa-20041220.t+=	http://www.ofug.net/~yamajun/files/
.endif

post-patch:
.if !empty(PKG_OPTIONS:M2ch_dict)
	${CP} ${DISTDIR}/2ch.t ${WRKSRC}/mkanthydic
	@printf '/^EXTRA_DICS\ns/$$/ 2ch.t/\nwq\n' | \
		ed -s ${WRKSRC}/mkanthydic/Makefile.in
.endif
.if !empty(PKG_OPTIONS:Mokinawa_dict)
	${CP} ${DISTDIR}/okinawa-20041220.t ${WRKSRC}/mkanthydic
	@printf '/^EXTRA_DICS\ns/$$/ okinawa-20041220.t/\nwq\n' | \
		ed -s ${WRKSRC}/mkanthydic/Makefile.in
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/doc/DICUTIL ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/doc/ELISP ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/doc/GUIDE.english ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/anthy

.include "../../mk/bsd.pkg.mk"
