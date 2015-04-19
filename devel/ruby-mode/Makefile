# $NetBSD: Makefile,v 1.32 2015/04/19 16:29:49 taca Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${EMACS_PKGNAME_PREFIX}${RUBY_PKGPREFIX}-mode-${RUBY_VERSION_FULL}
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby editing mode for Emacs

DISTINFO_FILE=		${RUBY_DISTINFO_FILE}
WRKSRC=			${RUBY_WRKSRC}/misc
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/misc
RUBY_VERSION_SUPPORTED=	22
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
