# $NetBSD: Makefile,v 1.1.1.1 2002/09/16 13:20:43 uebayasi Exp $
#

DISTNAME=	ddskk20020915
PKGNAME=	ddskk-20020915
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/skk/maintrunk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://openlab.ring.gr.jp/skk/index.html
COMMENT=	

DEPENDS=	apel>=10.2:../../devel/apel

MAKEFLAGS=	EMACS=${EMACS_BIN}
ALL_TARGET=	elc

INFO_FILES=	skk.info

do-configure:
	@${MV} ${WRKSRC}/SKK-CFG ${WRKSRC}/SKK-CFG.orig
	@${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		-e 's|@EMACS_LISPPREFIX@|${EMACS_LISPPREFIX}|g' \
	${FILESDIR}/SKK-CFG >${WRKSRC}/SKK-CFG

.include "../../mk/emacs.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
