# $NetBSD: Makefile,v 1.17 2012/10/06 14:25:10 asau Exp $

.include	"../../inputmethod/anthy/Makefile.common"

EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	taya@NetBSD.org
COMMENT=	Kana Kanji conversion system

USE_LIBTOOL=		yes
USE_LANGUAGES=		c
USE_TOOLS+=		printf
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		EMACS=no
EGDIR=			${PREFIX}/share/examples/anthy
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
INSTALLATION_DIRS=	share/doc/anthy
CONF_FILES+=		${EGDIR}/anthy-conf ${PKG_SYSCONFDIR}/anthy-conf

PKGCONFIG_OVERRIDE+=	anthy.pc.in

UNLIMIT_RESOURCES+=	stacksize

.include	"options.mk"


post-patch:
.if !empty(PKG_OPTIONS:Manthy-2ch-dict)
	${CP} ${DISTDIR}/2ch.t ${WRKSRC}/mkworddic
	# Don't change "\n".
	@${PRINTF} "/read @top_srcdir@\\\\/mkworddic\\\\/base.t\na\nread @top_srcdir@/mkworddic/2ch.t\n.\nw\n" | \
	ed -s ${WRKSRC}/mkworddic/dict.args.in
.endif
.if !empty(PKG_OPTIONS:Manthy-okinawa-dict)
	${CP} ${DISTDIR}/${OKIDIC_VERSION}.t ${WRKSRC}/mkworddic/okinawa.t
	# Don't change "\n".
	@${PRINTF} "/read @top_srcdir@\\\\/mkworddic\\\\/base.t\na\nread @top_srcdir@/mkworddic/okinawa.t\n.\nw\n" | \
	ed -s ${WRKSRC}/mkworddic/dict.args.in
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/DICUTIL ${DESTDIR}${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/doc/ELISP ${DESTDIR}${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/doc/GUIDE.english ${DESTDIR}${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/anthy
	${INSTALL_DATA} ${WRKSRC}/README.en ${DESTDIR}${PREFIX}/share/doc/anthy

.include "../../mk/bsd.pkg.mk"
