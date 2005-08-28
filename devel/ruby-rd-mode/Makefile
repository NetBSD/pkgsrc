# $NetBSD: Makefile,v 1.13 2005/08/28 04:25:29 uebayasi Exp $
#

DISTNAME=	rdtool-${RUBY_RD_VERSION}
PKGNAME=	${EMACS_PKGNAME_PREFIX}${RUBY_PKGPREFIX}-rd-mode-${RUBY_RD_VERSION}
CATEGORIES=	devel ruby
MASTER_SITES=	http://www2.pos.to/~tosh/ruby/rdtool/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www2.pos.to/~tosh/ruby/rdtool/
COMMENT=	Editing mode for RD (Ruby Document Format)

WRKSRC=			${WRKDIR}/${DISTNAME}/utils
EXTRACT_ELEMENTS=	${DISTNAME}/utils/rd-mode.el
RUBY_VERSION=		${RUBY18_VERSION}
RUBY_NOVERSION=		yes
NO_CONFIGURE=		yes

do-build:
	cd ${WRKSRC}; ${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile rd-mode.el

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/rd-mode
	${INSTALL_DATA} ${WRKSRC}/rd-mode.el ${EMACS_LISPPREFIX}/rd-mode
	${INSTALL_DATA} ${WRKSRC}/rd-mode.elc ${EMACS_LISPPREFIX}/rd-mode

.include "../../lang/ruby/rubyversion.mk"
.include "../../textproc/ruby-rdtool/rdversion.mk"
.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
