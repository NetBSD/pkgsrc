# $NetBSD: Makefile,v 1.10 2004/05/08 15:10:58 uebayasi Exp $
#

DISTNAME=	rdtool-${RUBY_RD_VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}rd-mode-${RUBY_RD_VERSION}
CATEGORIES=	devel ruby
MASTER_SITES=	http://www2.pos.to/~tosh/ruby/rdtool/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www2.pos.to/~tosh/ruby/rdtool/
COMMENT=	Editing mode for RD (Ruby Document Format)

WRKSRC=		${WRKDIR}/${DISTNAME}/utils
EXTRACT_ELEMENTS= ${DISTNAME}/utils/rd-mode.el
DIST_SUBDIR=	ruby
NO_CONFIGURE=	# defined

do-build:
	cd ${WRKSRC}; ${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile rd-mode.el

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/rd-mode
	${INSTALL_DATA} ${WRKSRC}/rd-mode.el ${EMACS_LISPPREFIX}/rd-mode
	${INSTALL_DATA} ${WRKSRC}/rd-mode.elc ${EMACS_LISPPREFIX}/rd-mode

.include "../../textproc/ruby-rdtool/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
