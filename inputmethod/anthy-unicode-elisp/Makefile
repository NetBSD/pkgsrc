# $NetBSD: Makefile,v 1.1 2026/08/28 11:30:35 wiz Exp $

.include	"../../inputmethod/anthy-unicode/Makefile.common"

PKGNAME=	${EMACS_PKGNAME_PREFIX}anthy-unicode-elisp-${ANTHY_UNICODE_VERSION}
CATEGORIES=	inputmethod editors

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Emacs lisp files for inputmethod/anthy-unicode

DEPENDS+=	anthy-unicode>=${ANTHY_UNICODE_VERSION}:../../inputmethod/anthy-unicode

USE_LIBTOOL=		yes
CONFIGURE_ENV+=		EMACS=${EMACS_BIN:Q}
EMACS_MODULES+=		base leim

# The accepted versions were measured, not guessed: on NetBSD 11.0/amd64 the
# package was built with emacs26, 28, 29, 30 and 31, and with emacs20.7 and
# emacs21.4, and japanese-anthy-unicode was driven through a conversion
# (nihongo -> the kanji) and deactivate-input-method in each.
#
# emacs20 and emacs21 additionally need the patch
# (patch-src-util_anthy-unicode.el) and Mule-UCS; see the
# EMACS_VERSION_MAJOR < 22 block below.
EMACS_VERSIONS_ACCEPTED=	emacs29 emacs29nox
EMACS_VERSIONS_ACCEPTED+=	emacs30 emacs30nox
EMACS_VERSIONS_ACCEPTED+=	emacs31 emacs31nox
EMACS_VERSIONS_ACCEPTED+=	emacs21 emacs21nox emacs20

.include "../../editors/emacs/modules.mk"

.if ${EMACS_VERSION_MAJOR} < 22
# anthy-agent-unicode speaks UTF-8 and nothing else (src-util/input.c sets
# ANTHY_UTF8_ENCODING unconditionally; --eucjp only reaches the --egg
# protocol).  But Emacs 20 has no utf-8 coding system at all, and Emacs 21's
# mule-utf-8 cannot represent CJK: the mule-unicode-* charsets cover
# U+0100-U+33FF and U+E000-U+FFFF but not U+4E00-U+9FFF, and utf-translate-cjk
# only arrives in Emacs 22.  Mule-UCS supplies a utf-8 that maps CJK onto
# japanese-jisx0208, so both versions work through it.
#
# It is needed for byte compilation too: the 20/21 byte compiler writes the
# decoded buffer with no-conversion, so the mule-unicode internal form (a
# 4-byte sequence starting 0x9C) lands in the .elc verbatim and cannot be
# read back.  Through Mule-UCS it becomes the 3-byte jisx0208 form and round
# trips.
DEPENDS+=	${EMACS_PKGNAME_PREFIX}Mule-UCS-[0-9]*:../../editors/mule-ucs
ELISP_PRELOAD=	-L ${EMACS_LISPPREFIX}/mule-ucs -l un-define
.endif

ELISP_EL=	anthy-unicode.el anthy-unicode-azik.el anthy-unicode-conf.el \
		anthy-unicode-dic.el anthy-unicode-isearch.el \
		anthy-unicode-kyuri.el

# Byte compile here rather than through the upstream Makefile (elisp-comp),
# for two reasons: ELISP_PRELOAD has to be fed in first, and leim-list.el has
# to be left out.  leim-list.el carries a no-byte-compile cookie on its first
# line, but that cookie is only honoured from Emacs 22 on; the 20 and 21
# batch-byte-compile write a leim-list.elc anyway, which is not in PLIST and
# makes the install fail.
do-build:
	cd ${WRKSRC}/src-util && ${EMACS_BIN} -batch -q -no-site-file \
		${ELISP_PRELOAD} -L . -f batch-byte-compile ${ELISP_EL}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/anthy-unicode
	${INSTALL_DATA} ${WRKSRC}/src-util/*.el	${DESTDIR}${EMACS_LISPPREFIX}/anthy-unicode
	${INSTALL_DATA} ${WRKSRC}/src-util/*.elc ${DESTDIR}${EMACS_LISPPREFIX}/anthy-unicode

.include "../../mk/bsd.pkg.mk"
