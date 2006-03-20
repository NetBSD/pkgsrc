# $NetBSD: Makefile,v 1.13 2006/03/20 05:30:33 jlam Exp $
#

DISTNAME=	ddskk-12.2.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}skk-12.2.0
PKGREVISION=	4
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/skk/maintrunk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/skk/index.html
COMMENT=	Japanese input methods for Emacs

CONFLICTS=	ddskk-[0-9]*

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox xemacs214 emacs20 xemacs215

EMACS_MODULES+=	base leim

.include "../../mk/emacs.mk"
.include "options.mk"

DEPENDS+=	${EMACS_PKGNAME_PREFIX}apel>=10.6:../../devel/apel
.if ${EMACS_FLAVOR} == "emacs"
BUILD_DEPENDS+=	${EMACS_PKGNAME_PREFIX}Mule-UCS-[0-9]*:../../editors/mule-ucs
.endif

MAKEFLAGS+=	EMACS=${EMACS_BIN:Q}
BUILD_TARGET=	elc

INFO_FILES=	skk.info

# SKK-CFG was copied from ${FILESDIR} during post-extract.
SUBST_CLASSES+=		cfg
SUBST_STAGE.cfg=	do-configure
SUBST_FILES.cfg=	SKK-CFG
SUBST_SED.cfg=		-e 's|@PREFIX@|${PREFIX}|g' \
			-e 's|@EMACS_LISPPREFIX@|${EMACS_LISPPREFIX}|g'

# Substitute directory definitions during do-configure.
post-extract:
	@${MV} ${WRKSRC}/SKK-CFG ${WRKSRC}/SKK-CFG.orig
	@${CP} ${FILESDIR}/SKK-CFG ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
