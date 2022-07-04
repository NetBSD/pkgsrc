# $NetBSD: Makefile,v 1.42 2022/07/04 14:40:40 ryoon Exp $

DISTNAME=	ddskk-ddskk-17.1_Neppu
PKGNAME=	${EMACS_PKGNAME_PREFIX}skk-17.1
PKGREVISION=	2
CATEGORIES=	japanese inputmethod
MASTER_SITES=	${MASTER_SITE_GITHUB:=skk-dev/}
GITHUB_PROJECT=	ddskk
GITHUB_TAG=	ddskk-17.1_Neppu

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/skk/index.html
COMMENT=	Japanese input methods for Emacs
LICENSE=	gnu-gpl-v2

CONFLICTS=	ddskk-[0-9]*

EMACS_MODULES+=		base leim
EMACS_BUILDLINK=	YES

EMACS_VERSIONS_ACCEPTED=	emacs28 emacs28nox
EMACS_VERSIONS_ACCEPTED+=	emacs27 emacs27nox
EMACS_VERSIONS_ACCEPTED+=	emacs26 emacs26nox
EMACS_VERSIONS_ACCEPTED+=	emacs25 emacs25nox

MAKE_FLAGS+=	EMACS=${EMACS_BIN:Q}
MAKE_ENV=	prefix=${DESTDIR:Q}${PREFIX:Q} \
		EMACS_INFOPREFIX=${DESTDIR:Q}${EMACS_INFOPREFIX:Q} \
		EMACS_LISPPREFIX=${DESTDIR:Q}${EMACS_LISPPREFIX:Q}
BUILD_TARGET=	elc

INFO_FILES=	YES

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fix user-destdir pathes.
SUBST_FILES.fix-paths=		skk-setup.el.in
SUBST_SED.fix-paths=		-e 's,@TUT@,${PREFIX}/share/skk/SKK.tut,g'

# Substitute directory definitions during do-configure.
post-extract:
	set -e; \
	${MV} ${WRKSRC}/SKK-CFG ${WRKSRC}/SKK-CFG.orig; \
	${CP} ${FILESDIR}/SKK-CFG ${WRKSRC}

.include "options.mk"

.include "../../editors/emacs/modules.mk"

PLIST_VARS+=	jisx0213

.if ${EMACS_VERSION_MAJOR} >= 21
PLIST.jisx0213=	yes
.endif

.if ${EMACS_VERSION_MAJOR} == 21
.  include "../../devel/apel/buildlink3.mk"
.endif
.include "../../editors/mule-ucs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
