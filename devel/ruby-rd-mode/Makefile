# $NetBSD: Makefile,v 1.26 2011/11/08 16:35:36 taca Exp $
#

DISTNAME=	rdtool-${RUBY_RD_VERSION}
PKGNAME=	${EMACS_PKGNAME_PREFIX}${RUBY_PKGPREFIX}-rd-mode-${RUBY_RD_VERSION}
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/33346/
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rdtool/
COMMENT=	Editing mode for RD (Ruby Document Format)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/utils
EXTRACT_ELEMENTS=	${DISTNAME}/utils/rd-mode.el
RUBY_RD_VERSION=	0.6.22
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
.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
