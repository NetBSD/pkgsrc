# $NetBSD: Makefile,v 1.1.1.1 2003/03/01 09:21:50 uebayasi Exp $

DISTNAME=	emacs-packages-0.0
CATEGORIES=	meta-pkgs editors
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	uebayasi@netbsd.org
HOMEPAGE=	# empty
COMMENT=	meta-package for the GNU Emacs lisp packages

.include "../../mk/emacs.mk"

DEPENDS+=	apel-[0-9]*:../../devel/apel
DEPENDS+=	artist-[0-9]*:../../graphics/artist
DEPENDS+=	auctex-[0-9]*:../../print/auctex
.if defined(_EMACS_VERSION_EMACS_MAJOR) && ${_EMACS_VERSION_EMACS_MAJOR} == "20"
DEPENDS+=	calc-[0-9]*:../../math/calc
.endif
DEPENDS+=	ddskk-[0-9]*:../../inputmethod/ddskk
DEPENDS+=	eieio-[0-9]*:../../lang/eieio
DEPENDS+=	elib-[0-9]*:../../devel/elib
DEPENDS+=	emacs-dict-client-[0-9]*:../../textproc/emacs-dict-client
DEPENDS+=	emacs-ilisp-[0-9]*:../../devel/emacs-ilisp
DEPENDS+=	emacs-w3m-[0-9]*:../../www/emacs-w3m
DEPENDS+=	etach-[0-9]*:../../mail/etach
DEPENDS+=	flim-[0-9]*:../../devel/flim
DEPENDS+=	haskell-mode-[0-9]*:../../devel/haskell-mode
DEPENDS+=	iiimecf-[0-9]*:../../inputmethod/iiimecf
DEPENDS+=	irchat-pj-[0-9]*:../../chat/irchat-pj
.if defined(_EMACS_VERSION_EMACS_MAJOR) && ${_EMACS_VERSION_EMACS_MAJOR} == "21"
#DEPENDS+=	jde-[0-9]*:../../editors/jde
.endif
DEPENDS+=	liece-[0-9]*:../../chat/liece
DEPENDS+=	lookup-[0-9]*:../../misc/lookup
DEPENDS+=	mailcrypt-[0-9]*:../../mail/mailcrypt
#DEPENDS+=	mew-[0-9]*:../../mail/mew
DEPENDS+=	mew-[0-9]*:../../mail/mew3
DEPENDS+=	Mule-UCS-[0-9]*:../../editors/mule-ucs
DEPENDS+=	navi2ch-[0-9]*:../../chat/navi2ch
.if defined(_EMACS_VERSION_EMACS_MAJOR) && ${_EMACS_VERSION_EMACS_MAJOR} == "20"
DEPENDS+=	pcl-cvs-[0-9]*:../../devel/pcl-cvs
.endif
#DEPENDS+=	pvs-[0-9]*:../../devel/pvs	# XXX pvs-license
DEPENDS+=	psgml-[0-9]*:../../textproc/psgml
DEPENDS+=	python-mode-[0-9]*:../../devel/python-mode
DEPENDS+=	ruby-mode-[0-9]*:../../devel/ruby-mode
DEPENDS+=	ruby-rd-mode-[0-9]*:../../devel/ruby-rd-mode
DEPENDS+=	semantic-[0-9]*:../../devel/semantic
DEPENDS+=	semi-[0-9]*:../../devel/semi
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
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
