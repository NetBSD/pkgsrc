# $NetBSD: Makefile,v 1.6 2002/11/30 13:29:21 taca Exp $
#

DISTNAME=	ddskk-20021124
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/skk/maintrunk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://openlab.ring.gr.jp/skk/index.html
COMMENT=	Japanese input methods for Emacs

DEPENDS=	${PKGNAME_PREFIX}apel>=10.2:../../devel/apel

MAKEFLAGS=	EMACS=${EMACS_BIN}
ALL_TARGET=	elc

INFO_FILES=	skk.info

do-configure:
	@${MV} ${WRKSRC}/SKK-CFG ${WRKSRC}/SKK-CFG.orig
	@${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		-e 's|@EMACS_LISPPREFIX@|${EMACS_LISPPREFIX}|g' \
	${FILESDIR}/SKK-CFG >${WRKSRC}/SKK-CFG

# Create PLIST, since some files are installed conditionally and what
# file will be installed is hard to expect before configure / build.
# The idea here is that files compiled as *.elc will be installed.
post-build:
	@{ \
		${CAT} ${PKGDIR}/PLIST.header; \
		cd ${WRKSRC}; \
		for e in *.elc; do \
			${ECHO} '$${EMACS_LISPPREFIX}/skk/'$${e%.elc}.el; \
			${ECHO} '$${EMACS_LISPPREFIX}/skk/'$$e; \
		done; \
		${CAT} ${PKGDIR}/PLIST.footer; \
	} >${PKGDIR}/PLIST

.include "../../mk/emacs.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
