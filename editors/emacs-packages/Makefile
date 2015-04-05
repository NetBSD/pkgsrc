# $NetBSD: Makefile,v 1.29 2015/04/05 20:09:05 jnemeth Exp $

DISTNAME=	emacs-packages-0.10
CATEGORIES=	meta-pkgs editors
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Meta-package for the GNU Emacs lisp packages

META_PACKAGE=	# empty

.include "../../editors/emacs/modules.mk"

# XXX
# Please update the version of this package (emacs-package) when you
# add a new emacs lisp package below!
DEPENDS+=	${EMACS_PKGNAME_PREFIX}apel-[0-9]*:../../devel/apel
DEPENDS+=	${EMACS_PKGNAME_PREFIX}artist-[0-9]*:../../graphics/artist
DEPENDS+=	${EMACS_PKGNAME_PREFIX}auctex-[0-9]*:../../print/auctex
DEPENDS+=	${EMACS_PKGNAME_PREFIX}bbdb-[0-9]*:../../misc/bbdb
.if defined(_EMACS_VERSION_EMACS_MAJOR) && ${_EMACS_VERSION_EMACS_MAJOR} == "20"
DEPENDS+=	${EMACS_PKGNAME_PREFIX}calc-[0-9]*:../../math/calc
.endif
DEPENDS+=	${EMACS_PKGNAME_PREFIX}doxymacs-[0-9]*:../../devel/doxymacs
.if ${EMACS_VERSION_MAJOR} < 23
DEPENDS+=	${EMACS_PKGNAME_PREFIX}eieio-[0-9]*:../../lang/eieio
.endif
DEPENDS+=	${EMACS_PKGNAME_PREFIX}elib-[0-9]*:../../devel/elib
.if ${EMACS_VERSION_MAJOR} < 24
DEPENDS+=	${EMACS_PKGNAME_PREFIX}elscreen-[0-9]*:../../misc/elscreen
.endif
DEPENDS+=	${EMACS_PKGNAME_PREFIX}emacs-dict-client-[0-9]*:../../textproc/emacs-dict-client
DEPENDS+=	${EMACS_PKGNAME_PREFIX}emacs-ilisp-[0-9]*:../../devel/emacs-ilisp
.if ${EMACS_VERSION_MAJOR} < 23
DEPENDS+=	${EMACS_PKGNAME_PREFIX}emacs-w3m-[0-9]*:../../www/emacs-w3m
.else
DEPENDS+=	${EMACS_PKGNAME_PREFIX}emacs-w3m-[0-9]*:../../www/emacs-w3m-snapshot
.endif
DEPENDS+=	${EMACS_PKGNAME_PREFIX}ess-[0-9]*:../../math/ess
DEPENDS+=	${EMACS_PKGNAME_PREFIX}etach-[0-9]*:../../mail/etach
DEPENDS+=	${EMACS_PKGNAME_PREFIX}flim-[0-9]*:../../devel/flim
DEPENDS+=	${EMACS_PKGNAME_PREFIX}flyspell-[0-9]*:../../textproc/flyspell
DEPENDS+=	${EMACS_PKGNAME_PREFIX}haskell-mode-[0-9]*:../../devel/haskell-mode
.if ${EMACS_VERSION_MAJOR} == "21"
DEPENDS+=	${EMACS_PKGNAME_PREFIX}iiimecf-[0-9]*:../../inputmethod/iiimecf
.endif
DEPENDS+=	${EMACS_PKGNAME_PREFIX}irchat-pj-[0-9]*:../../chat/irchat-pj
DEPENDS+=	${EMACS_PKGNAME_PREFIX}ispell-emacs-[0-9]*:../../textproc/ispell-emacs
#.if defined(_EMACS_VERSION_EMACS_MAJOR) && ${_EMACS_VERSION_EMACS_MAJOR} == "21"
#DEPENDS+=	${EMACS_PKGNAME_PREFIX}jde-[0-9]*:../../editors/jde
#.endif
DEPENDS+=	${EMACS_PKGNAME_PREFIX}riece-[0-9]*:../../chat/riece
#DEPENDS+=	${EMACS_PKGNAME_PREFIX}lookup-[0-9]*:../../misc/lookup
DEPENDS+=	${EMACS_PKGNAME_PREFIX}mailcrypt-[0-9]*:../../mail/mailcrypt
DEPENDS+=	${EMACS_PKGNAME_PREFIX}matlab-mode-[0-9]*:../../editors/matlab-mode
DEPENDS+=	${EMACS_PKGNAME_PREFIX}mew-[0-9]*:../../mail/mew
.if ${EMACS_VERSION_MAJOR} == "21"
DEPENDS+=	${EMACS_PKGNAME_PREFIX}Mule-UCS-[0-9]*:../../editors/mule-ucs
.endif
.if defined(_EMACS_VERSION_EMACS_MAJOR) && ${_EMACS_VERSION_EMACS_MAJOR} == "20"
DEPENDS+=	${EMACS_PKGNAME_PREFIX}pcl-cvs-[0-9]*:../../devel/pcl-cvs
.endif
#DEPENDS+=	${EMACS_PKGNAME_PREFIX}pvs-[0-9]*:../../devel/pvs	# XXX pvs-license
DEPENDS+=	${EMACS_PKGNAME_PREFIX}psgml-mode-[0-9]*:../../textproc/psgml-mode
DEPENDS+=	${EMACS_PKGNAME_PREFIX}python-mode-[0-9]*:../../devel/python-mode
DEPENDS+=	${EMACS_PKGNAME_PREFIX}ruby-mode-[0-9]*:../../devel/ruby-mode
DEPENDS+=	${EMACS_PKGNAME_PREFIX}ruby-rd-mode-[0-9]*:../../devel/ruby-rd-mode
.if ${EMACS_VERSION_MAJOR} < 23
DEPENDS+=	${EMACS_PKGNAME_PREFIX}semantic-[0-9]*:../../devel/semantic
.endif
DEPENDS+=	${EMACS_PKGNAME_PREFIX}semi-[0-9]*:../../devel/semi
DEPENDS+=	${EMACS_PKGNAME_PREFIX}skk-[0-9]*:../../inputmethod/skk
DEPENDS+=	${EMACS_PKGNAME_PREFIX}sml-mode-[0-9]*:../../devel/sml-mode
DEPENDS+=	${EMACS_PKGNAME_PREFIX}speedbar-[0-9]*:../../editors/speedbar
DEPENDS+=	${EMACS_PKGNAME_PREFIX}tamago-[0-9]*:../../editors/tamago
DEPENDS+=	${EMACS_PKGNAME_PREFIX}tc-[0-9]*:../../inputmethod/tc
DEPENDS+=	${EMACS_PKGNAME_PREFIX}verilog-mode-[0-9]*:../../cad/verilog-mode
DEPENDS+=	${EMACS_PKGNAME_PREFIX}vm-[0-9]*:../../mail/vm
.if ${EMACS_VERSION_MAJOR} < 22
DEPENDS+=	${EMACS_PKGNAME_PREFIX}w3-[0-9]*:../../www/w3
.endif
.if ${EMACS_VERSION_MAJOR} < 23
DEPENDS+=	${EMACS_PKGNAME_PREFIX}wl-[0-9]*:../../mail/wl
.else
DEPENDS+=	${EMACS_PKGNAME_PREFIX}wl-[0-9]*:../../mail/wl-snapshot
.endif
DEPENDS+=	${EMACS_PKGNAME_PREFIX}zenicb-[0-9]*:../../chat/zenicb
DEPENDS+=	${EMACS_PKGNAME_PREFIX}zenirc-[0-9]*:../../chat/zenirc

.include "../../mk/bsd.pkg.mk"
