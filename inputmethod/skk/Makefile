# $NetBSD: Makefile,v 1.1.1.1 2003/09/02 14:16:45 minoura Exp $
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
.else # xemacs
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
