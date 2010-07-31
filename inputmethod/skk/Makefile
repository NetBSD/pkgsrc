# $NetBSD: Makefile,v 1.21 2010/07/31 08:45:09 obache Exp $
#

DISTNAME=	ddskk-14.0.91
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/^ddskk/skk/}
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/skk/maintrunk/ \
		http://openlab.ring.gr.jp/skk/maintrunk/old-releases/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/skk/index.html
COMMENT=	Japanese input methods for Emacs
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	ddskk-[0-9]*

EMACS_MODULES+=	base leim
EMACS_BUILDLINK=# defined

MAKE_FLAGS+=	EMACS=${EMACS_BIN:Q}
MAKE_ENV=	prefix=${DESTDIR:Q}${PREFIX:Q} \
		EMACS_INFOPREFIX=${DESTDIR:Q}${EMACS_INFOPREFIX:Q} \
		EMACS_LISPPREFIX=${DESTDIR:Q}${EMACS_LISPPREFIX:Q}
BUILD_TARGET=	elc

INFO_FILES=	# PLIST

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fix user-destdir pathes.
SUBST_FILES.fix-paths=		skk-setup.el.in
SUBST_SED.fix-paths=		-e 's,@TUT@,${PREFIX}/share/skk/SKK.tut,g'

# Substitute directory definitions during do-configure.
post-extract:
	@${MV} ${WRKSRC}/SKK-CFG ${WRKSRC}/SKK-CFG.orig
	@${CP} ${FILESDIR}/SKK-CFG ${WRKSRC}
	@${CHMOD} +w ${WRKSRC}/skk-dic.* ${WRKSRC}/doc/skk.texi

.include "options.mk"

.include "../../editors/emacs/modules.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../editors/mule-ucs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
