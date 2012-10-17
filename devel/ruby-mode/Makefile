# $NetBSD: Makefile,v 1.25.6.1 2012/10/17 09:47:20 tron Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${EMACS_PKGNAME_PREFIX}${RUBY_PKGPREFIX}-mode-${RUBY_VERSION_FULL}
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby editing mode for Emacs

PKG_DESTDIR_SUPPORT=	user-destdir

DISTINFO_FILE=		${RUBY_DISTINFO_FILE}
WRKSRC=			${RUBY_WRKSRC}/misc
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/misc
RUBY_VERSION_SUPPORTED=	193
RUBY_NOVERSION=		yes
NO_CONFIGURE=		yes
SRCS=			inf-ruby.el ruby-electric.el ruby-mode.el \
			ruby-style.el rubydb3x.el

do-build:
	for f in ${SRCS}; do \
		cd ${WRKSRC}; \
		${EMACS_BIN} --no-init-file --no-site-file -batch \
			-l ruby-mode.el -f batch-byte-compile $$f; \
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/ruby-mode
	cd ${WRKSRC}; \
		${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} \
			${DESTDIR}${EMACS_LISPPREFIX}/ruby-mode

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
