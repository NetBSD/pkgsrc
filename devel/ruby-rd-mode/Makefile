# $NetBSD: Makefile,v 1.32 2026/02/17 14:34:52 taca Exp $
#

DISTNAME=	rdtool-${RUBY_RD_VERSION}
PKGNAME=	${EMACS_PKGNAME_PREFIX}ruby-rd-mode-${RUBY_RD_VERSION}
CATEGORIES=	devel ruby
EXTRACT_SUFX?=	.gem

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://uwabami.github.io/software/rdtool/
COMMENT=	Editing mode for RD (Ruby Document Format)
LICENSE=	ruby-license OR gnu-gpl-v2

BUILD_DEPENDS+=	${RUBY_BASE}>=${RUBY_VERSION}:${RUBY_SRCDIR}

WRKSRC=			${WRKDIR}/${DISTNAME}/utils
EXTRACT_ELEMENTS=	${DISTNAME}/utils/rd-mode.el
RUBY_RD_VERSION=	0.6.38
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/rd-mode

do-build:
	cd ${WRKSRC}; ${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile rd-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/rd-mode.el ${DESTDIR}${EMACS_LISPPREFIX}/rd-mode
	${INSTALL_DATA} ${WRKSRC}/rd-mode.elc ${DESTDIR}${EMACS_LISPPREFIX}/rd-mode

.include "../../lang/ruby/gem-extract.mk"
.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
