# $NetBSD: Makefile,v 1.7 2005/03/05 11:19:10 uebayasi Exp $
#

DISTNAME=	ddskk-12.2.0
PKGNAME=	skk-12.2.0
PKGREVISION=	1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/skk/maintrunk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/skk/index.html
COMMENT=	Japanese input methods for Emacs

CONFLICTS=	ddskk-*

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox xemacs214 emacs20 xemacs215

.include "../../mk/emacs.mk"
.include "options.mk"

DEPENDS=	${PKGNAME_PREFIX}apel>=10.6:../../devel/apel
.if ${EMACS_FLAVOR} == "emacs"
EMACS_USE_LEIM=	# defined
BUILD_DEPENDS+=	${PKGNAME_PREFIX}Mule-UCS-*:../../editors/mule-ucs
.else
BUILD_DEPENDS+= ${PKGNAME_PREFIX}xemacs-packages>=1.10:../../editors/xemacs-packages
.endif

MAKEFLAGS=	EMACS=${EMACS_BIN}
BUILD_TARGET=	elc

INFO_FILES=	skk.info

# SKK-CFG was copied from ${FILESDIR} during post-extract.
SUBST_CLASSES=		cfg
SUBST_STAGE.cfg=	do-configure
SUBST_FILES.cfg=	SKK-CFG
SUBST_SED.cfg=		-e 's|@PREFIX@|${PREFIX}|g' \
			-e 's|@EMACS_LISPPREFIX@|${EMACS_LISPPREFIX}|g'

# Substitute directory definitions during do-configure.
post-extract:
	@${MV} ${WRKSRC}/SKK-CFG ${WRKSRC}/SKK-CFG.orig
	@${CP} ${FILESDIR}/SKK-CFG ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
