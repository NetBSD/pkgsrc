# $NetBSD: Makefile,v 1.7 2004/01/20 12:13:29 agc Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGNAMEPREFIX}mode-${RUBY_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www2.pos.to/~tosh/ruby/rdtool/
COMMENT=	Ruby editing mode for Emacs

DIST_SUBDIR=	ruby
WRKSRC=		${RUBY_WRKSRC}/misc

.include "../../mk/bsd.prefs.mk"
RUBY_VER=	1.6		# always use 1.6 base

EXTRACT_ELEMENTS= ${RUBY_DISTNAME}/misc
NO_CONFIGURE=	# defined

SRCS=	${RUBY_WRKSRC}/misc/ruby-mode.el \
	${RUBY_WRKSRC}/misc/rubydb3x.el \
	${RUBY_WRKSRC}/misc/inf-ruby.el

PLIST_SUBST+=	SITE_LISP=${SITE_LISP}

do-build:
	for f in ${SRCS}; do \
		cd ${WRKSRC}; \
		${EMACS_BIN} --no-init-file --no-site-file -batch \
			-l ruby-mode.el -f batch-byte-compile $$f; \
	done

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/ruby-mode
	${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} ${EMACS_LISPPREFIX}/ruby-mode

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
