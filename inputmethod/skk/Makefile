# $NetBSD: Makefile,v 1.3 2003/09/13 06:07:10 minoura Exp $
#

DISTNAME=	ddskk-12.2.0
PKGNAME=	skk-12.2.0
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/skk/maintrunk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/skk/index.html
COMMENT=	Japanese input methods for Emacs

CONFLICTS=	ddskk-*

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox xemacs214 emacs20 xemacs215
.include "../../mk/emacs.mk"

DEPENDS=	${PKGNAME_PREFIX}apel>=10.6:../../devel/apel
.if ${EMACS_FLAVOR} == "emacs"
BUILD_DEPENDS+=	${PKGNAME_PREFIX}lookup-*:../../misc/lookup
EMACS_USE_LEIM=	# defined
.if ${_EMACS_VERSION} == "emacs21" || ${_EMACS_VERSION} == "emacs21nox"
BUILD_DEPENDS+=	Mule-UCS-*:../../editors/mule-ucs
.endif
.else # xemacs
PKGNAME=	xemacs-skk-12.2.0	# XXX
BUILD_DEPENDS+= xemacs-packages>=1.10:../../editors/xemacs-packages
.endif

MAKEFLAGS=	EMACS=${EMACS_BIN}
ALL_TARGET=	elc

INFO_FILES=	skk.info

do-configure:
	@${MV} ${WRKSRC}/SKK-CFG ${WRKSRC}/SKK-CFG.orig
	@${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		-e 's|@EMACS_LISPPREFIX@|${EMACS_LISPPREFIX}|g' \
	${FILESDIR}/SKK-CFG >${WRKSRC}/SKK-CFG

.include "../../mk/bsd.pkg.mk"
