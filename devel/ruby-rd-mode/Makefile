# $NetBSD: Makefile,v 1.20 2008/03/03 17:45:37 jlam Exp $
#

DISTNAME=	rdtool-${RUBY_RD_VERSION}
PKGNAME=	${EMACS_PKGNAME_PREFIX}${RUBY_PKGPREFIX}-rd-mode-${RUBY_RD_VERSION}
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www2.pos.to/~tosh/ruby/rdtool/
COMMENT=	Editing mode for RD (Ruby Document Format)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/utils
EXTRACT_ELEMENTS=	${DISTNAME}/utils/rd-mode.el
RUBY_RD_VERSION=	0.6.20
RUBY_VERSION=		${RUBY18_VERSION}
RUBY_NOVERSION=		yes
NO_CONFIGURE=		yes

do-build:
	cd ${WRKSRC}; ${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile rd-mode.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/rd-mode
	${INSTALL_DATA} ${WRKSRC}/rd-mode.el ${DESTDIR}${EMACS_LISPPREFIX}/rd-mode
	${INSTALL_DATA} ${WRKSRC}/rd-mode.elc ${DESTDIR}${EMACS_LISPPREFIX}/rd-mode

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
