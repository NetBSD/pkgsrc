# $NetBSD: Makefile,v 1.2 2001/12/23 15:58:51 taca Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGNAMEPREFIX}mode-${RUBY_VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www2.pos.to/~tosh/ruby/rdtool/
COMMENT=	Ruby editing mode for Emacs

DIST_SUBDIR=	ruby
WRKSRC=		${RUBY_WRKSRC}/misc

.include "../../mk/bsd.prefs.mk"
RUBY_VER=	1.6		# always use 1.6 base

.if defined(USE_XEMACS)
DEPENDS+=	xemacs-[0-9]*:../../editors/xemacs
EMACS=		xemacs
SITE_LISP=	lib/xemacs/xemacs-packages/lisp/prog-modes
.else
DEPENDS+=	emacs-[0-9]*:../../editors/emacs
EMACS=		emacs
SITE_LISP=	share/emacs/site-lisp
.endif

EXTRACT_ELEMENTS= ${RUBY_DISTNAME}/misc
NO_CONFIGURE=	# defined

SRCS=		ruby-mode.el rubydb3x.el inf-ruby.el

PLIST_SUBST+=	SITE_LISP=${SITE_LISP}

do-build:
.for f in ${SRCS}
	cd ${WRKSRC}; ${EMACS} --no-init-file --no-site-file -batch \
		-l ruby-mode.el -f batch-byte-compile ${f}
.endfor

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${SITE_LISP}
.for f in ${SRCS}
	${INSTALL_DATA} ${RUBY_WRKSRC}/misc/${f} ${PREFIX}/${SITE_LISP}
	${INSTALL_DATA} ${RUBY_WRKSRC}/misc/${f}c ${PREFIX}/${SITE_LISP}
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
