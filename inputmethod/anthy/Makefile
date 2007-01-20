# $NetBSD: Makefile,v 1.13 2007/01/20 17:11:52 wiz Exp $

.include	"../../inputmethod/anthy/Makefile.common"

EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	taya@NetBSD.org
COMMENT=	Kana Kanji conversion system

USE_LIBTOOL=		yes
USE_LANGUAGES=		c
USE_TOOLS+=		gmake printf
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		EMACS=no
EGDIR=			${PREFIX}/share/examples/anthy
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
CONF_FILES+=		${EGDIR}/anthy-conf ${PKG_SYSCONFDIR}/anthy-conf

PKGCONFIG_OVERRIDE+=	anthy.pc.in

.include	"options.mk"

post-patch:
.if !empty(PKG_OPTIONS:Manthy-2ch-dict)
	${CP} ${DISTDIR}/2ch.t ${WRKSRC}/mkworddic
	# Don't change "\n".
	@${PRINTF} "/read @top_srcdir@\\\\/mkworddic\\\\/placename.t\na\nread @top_srcdir@/mkworddic/2ch.t\n.\nw\n" | \
	ed -s ${WRKSRC}/mkworddic/dict.args.in
.endif
.if !empty(PKG_OPTIONS:Manthy-okinawa-dict)
	${CP} ${DISTDIR}/${OKIDIC_VERSION}.t ${WRKSRC}/mkworddic/okinawa.t
	# Don't change "\n".
	@${PRINTF} "/read @top_srcdir@\\\\/mkworddic\\\\/placename.t\na\nread @top_srcdir@/mkworddic/okinawa.t\n.\nw\n" | \
	ed -s ${WRKSRC}/mkworddic/dict.args.in
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/doc/DICUTIL ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/doc/ELISP ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/doc/GUIDE.english ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/README.en ${PREFIX}/share/doc/anthy

.include "../../mk/bsd.pkg.mk"
