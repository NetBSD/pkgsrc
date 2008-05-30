# $NetBSD: Makefile,v 1.17 2008/05/30 16:03:17 brook Exp $
#

DISTNAME=	ddskk-20080309
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/^ddskk/skk/}
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/skk/maintrunk/ \
		http://openlab.ring.gr.jp/skk/maintrunk/old-snapshots/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/skk/index.html
COMMENT=	Japanese input methods for Emacs

CONFLICTS=	ddskk-[0-9]*

EMACS_MODULES+=	base leim

MAKEFLAGS+=	EMACS=${EMACS_BIN:Q}
BUILD_TARGET=	elc

INFO_FILES=	# PLIST

# SKK-CFG was copied from ${FILESDIR} during post-extract.
SUBST_CLASSES+=		cfg
SUBST_STAGE.cfg=	do-configure
SUBST_FILES.cfg=	SKK-CFG
SUBST_SED.cfg=		-e 's|@PREFIX@|${PREFIX}|g'			\
			-e 's|@EMACS_INFOPREFIX@|${EMACS_INFOPREFIX}|g'	\
			-e 's|@EMACS_LISPPREFIX@|${EMACS_LISPPREFIX}|g'

# Substitute directory definitions during do-configure.
post-extract:
	@${MV} ${WRKSRC}/SKK-CFG ${WRKSRC}/SKK-CFG.orig
	@${CP} ${FILESDIR}/SKK-CFG ${WRKSRC}
	@${CHMOD} +w ${WRKSRC}/doc/skk.texi

.include "options.mk"

.include "../../mk/emacs.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../editors/mule-ucs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
