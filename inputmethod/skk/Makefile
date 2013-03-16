# $NetBSD: Makefile,v 1.29 2013/03/16 14:59:49 ryoon Exp $
#

DISTNAME=	ddskk-15.1
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/^ddskk/skk/}
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/skk/maintrunk/ \
		http://openlab.ring.gr.jp/skk/maintrunk/old-releases/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/skk/index.html
COMMENT=	Japanese input methods for Emacs
LICENSE=	gnu-gpl-v2

CONFLICTS=	ddskk-[0-9]*

EMACS_MODULES+=	base leim
EMACS_BUILDLINK=YES

EMACS_VERSIONS_ACCEPTED=	emacs24 emacs24nox emacs23 emacs23nox emacs22 emacs22nox

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

.if ${EMACS_VERSION_MAJOR} >= 23 || ${EMACS_VERSION_MAJOR} == 21
PLIST.jisx0213=	yes
.endif

.if ${EMACS_VERSION_MAJOR} == 21
.  include "../../devel/apel/buildlink3.mk"
.endif
.include "../../editors/mule-ucs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
