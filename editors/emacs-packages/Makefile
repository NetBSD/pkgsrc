# $NetBSD: Makefile,v 1.16 2004/11/30 15:42:02 wiz Exp $

DISTNAME=	emacs-packages-0.6
CATEGORIES=	meta-pkgs editors
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Meta-package for the GNU Emacs lisp packages

.include "../../mk/emacs.mk"

# XXX
# Please update the version of this package (emacs-package) when you #
# add a new emacs lisp package below!				     #
DEPENDS+=	apel-[0-9]*:../../devel/apel
DEPENDS+=	artist-[0-9]*:../../graphics/artist
DEPENDS+=	auctex-[0-9]*:../../print/auctex
DEPENDS+=	bbdb-[0-9]*:../../misc/bbdb
.if defined(_EMACS_VERSION_EMACS_MAJOR) && ${_EMACS_VERSION_EMACS_MAJOR} == "20"
DEPENDS+=	calc-[0-9]*:../../math/calc
.endif
DEPENDS+=	eieio-[0-9]*:../../lang/eieio
DEPENDS+=	elib-[0-9]*:../../devel/elib
DEPENDS+=	emacs-dict-client-[0-9]*:../../textproc/emacs-dict-client
DEPENDS+=	emacs-ilisp-[0-9]*:../../devel/emacs-ilisp
DEPENDS+=	emacs-w3m-[0-9]*:../../www/emacs-w3m
DEPENDS+=	ess-[0-9]*:../../math/ess
DEPENDS+=	etach-[0-9]*:../../mail/etach
DEPENDS+=	flim-[0-9]*:../../devel/flim
DEPENDS+=	flyspell-[0-9]*:../../textproc/flyspell
DEPENDS+=	haskell-mode-[0-9]*:../../devel/haskell-mode
DEPENDS+=	iiimecf-[0-9]*:../../inputmethod/iiimecf
DEPENDS+=	irchat-pj-[0-9]*:../../chat/irchat-pj
DEPENDS+=	ispell-emacs-[0-9]*:../../textproc/ispell-emacs
#.if defined(_EMACS_VERSION_EMACS_MAJOR) && ${_EMACS_VERSION_EMACS_MAJOR} == "21"
#DEPENDS+=	jde-[0-9]*:../../editors/jde
#.endif
DEPENDS+=	riece-[0-9]*:../../chat/riece
#DEPENDS+=	lookup-[0-9]*:../../misc/lookup
DEPENDS+=	mailcrypt-[0-9]*:../../mail/mailcrypt
DEPENDS+=	matlab-mode-*:../../editors/matlab-mode
#DEPENDS+=	mew-[0-9]*:../../mail/mew
DEPENDS+=	mew-[0-9]*:../../mail/mew3
DEPENDS+=	Mule-UCS-[0-9]*:../../editors/mule-ucs
DEPENDS+=	navi2ch-[0-9]*:../../chat/navi2ch
.if defined(_EMACS_VERSION_EMACS_MAJOR) && ${_EMACS_VERSION_EMACS_MAJOR} == "20"
DEPENDS+=	pcl-cvs-[0-9]*:../../devel/pcl-cvs
.endif
#DEPENDS+=	pvs-[0-9]*:../../devel/pvs	# XXX pvs-license
DEPENDS+=	psgml-mode-[0-9]*:../../textproc/psgml-mode
DEPENDS+=	python-mode-[0-9]*:../../devel/python-mode
DEPENDS+=	ruby-mode-[0-9]*:../../devel/ruby-mode
DEPENDS+=	ruby-rd-mode-[0-9]*:../../devel/ruby-rd-mode
DEPENDS+=	semantic-[0-9]*:../../devel/semantic
DEPENDS+=	semi-[0-9]*:../../devel/semi
DEPENDS+=	skk-[0-9]*:../../inputmethod/skk
DEPENDS+=	sml-mode-[0-9]*:../../devel/sml-mode
DEPENDS+=	speedbar-[0-9]*:../../editors/speedbar
DEPENDS+=	tamago-[0-9]*:../../editors/tamago
DEPENDS+=	tc-[0-9]*:../../inputmethod/tc
DEPENDS+=	verilog-mode-[0-9]*:../../cad/verilog-mode
DEPENDS+=	vm-[0-9]*:../../mail/vm
DEPENDS+=	w3-[0-9]*:../../www/w3
DEPENDS+=	wl-[0-9]*:../../mail/wl
DEPENDS+=	zenicb-[0-9]*:../../chat/zenicb
DEPENDS+=	zenirc-[0-9]*:../../chat/zenirc

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
