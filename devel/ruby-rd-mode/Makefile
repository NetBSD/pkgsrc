# $NetBSD: Makefile,v 1.22 2008/09/15 08:36:24 taca Exp $
#

DISTNAME=	rdtool-${RUBY_RD_VERSION}
PKGNAME=	${EMACS_PKGNAME_PREFIX}${RUBY_PKGPREFIX}-rd-mode-${RUBY_RD_VERSION}
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/33346/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rdtool/
COMMENT=	Editing mode for RD (Ruby Document Format)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/utils
EXTRACT_ELEMENTS=	${DISTNAME}/utils/rd-mode.el
RUBY_RD_VERSION=	0.6.22
RUBY_VERSION=		${RUBY18_VERSION}
RUBY_NOVERSION=		yes
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/rd-mode

do-build:
	cd ${WRKSRC}; ${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile rd-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/rd-mode.el ${DESTDIR}${EMACS_LISPPREFIX}/rd-mode
	${INSTALL_DATA} ${WRKSRC}/rd-mode.elc ${DESTDIR}${EMACS_LISPPREFIX}/rd-mode

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
