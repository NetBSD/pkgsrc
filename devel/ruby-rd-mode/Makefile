# $NetBSD: Makefile,v 1.8 2004/01/20 12:13:29 agc Exp $
#

DISTNAME=	rdtool-${RUBY_RD_VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}rd-mode-${RUBY_RD_VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://www2.pos.to/~tosh/ruby/rdtool/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www2.pos.to/~tosh/ruby/rdtool/
COMMENT=	Editing mode for RD (Ruby Document Format)

.if defined(USE_XEMACS)
DEPENDS+=	xemacs-[0-9]*:../../editors/xemacs
EMACS=		xemacs
SITE_LISP=	lib/xemacs/xemacs-packages/lisp/prog-modes
.else
DEPENDS+=	emacs-[0-9]*:../../editors/emacs
EMACS=		emacs
SITE_LISP=	share/emacs/site-lisp
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/utils
EXTRACT_ELEMENTS= ${DISTNAME}/utils/rd-mode.el
DIST_SUBDIR=	ruby
NO_CONFIGURE=	# defined

PLIST_SUBST+=	SITE_LISP=${SITE_LISP}

do-build:
	cd ${WRKSRC}; ${EMACS} --no-init-file --no-site-file -batch \
		-f batch-byte-compile rd-mode.el

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${SITE_LISP}
	${INSTALL_DATA} ${WRKSRC}/rd-mode.el ${PREFIX}/${SITE_LISP}
	${INSTALL_DATA} ${WRKSRC}/rd-mode.elc ${PREFIX}/${SITE_LISP}

.include "../../textproc/ruby-rdtool/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
