# $NetBSD: Makefile,v 1.18 2008/10/11 09:31:57 uebayasi Exp $
#

DISTNAME=	ddskk-20080309
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/^ddskk/skk/}
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/skk/maintrunk/ \
		http://openlab.ring.gr.jp/skk/maintrunk/old-snapshots/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/skk/index.html
COMMENT=	Japanese input methods for Emacs

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	ddskk-[0-9]*

EMACS_MODULES+=	base leim

MAKEFLAGS+=	EMACS=${EMACS_BIN:Q}
MAKE_ENV=	prefix=${DESTDIR:Q}${PREFIX:Q} \
		EMACS_INFOPREFIX=${DESTDIR:Q}${EMACS_INFOPREFIX:Q} \
		EMACS_LISPPREFIX=${DESTDIR:Q}${EMACS_LISPPREFIX:Q}
BUILD_TARGET=	elc

INFO_FILES=	# PLIST

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
