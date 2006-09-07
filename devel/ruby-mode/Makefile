# $NetBSD: Makefile,v 1.14 2006/09/07 15:46:12 taca Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${EMACS_PKGNAME_PREFIX}${RUBY_PKGPREFIX}-mode-${RUBY_VERSION}
#PKGREVISION=
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby editing mode for Emacs

DISTINFO_FILE=		${RUBY_DISTINFO_FILE}
WRKSRC=			${RUBY_WRKSRC}/misc
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/misc
RUBY_VERSION=		${RUBY18_VERSION}
RUBY_NOVERSION=		yes
NO_CONFIGURE=		yes
SRCS=			ruby-mode.el rubydb3x.el inf-ruby.el

PLIST_SUBST+=	SITE_LISP=${SITE_LISP:Q}

do-build:
	for f in ${SRCS}; do \
		cd ${WRKSRC}; \
		${EMACS_BIN} --no-init-file --no-site-file -batch \
			-l ruby-mode.el -f batch-byte-compile $$f; \
	done

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/ruby-mode
	cd ${WRKSRC}; \
		${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} \
			${EMACS_LISPPREFIX}/ruby-mode

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
