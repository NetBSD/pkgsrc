# $NetBSD: Makefile,v 1.18 2026/09/25 09:48:09 wiz Exp $

DISTNAME=		matlab.el
# we do this because we want DIST_SUBDIR to not change based on
# emacs vs xemacs
BASEPKGNAME=		matlab-mode-2.3.1
PKGNAME=		${EMACS_PKGNAME_PREFIX}${BASEPKGNAME}
PKGREVISION=		4
CATEGORIES=		editors math
MASTER_SITES=		http://www.mathworks.com/matlabcentral/files/104/
EXTRACT_SUFX=

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/mathworks/Emacs-MATLAB-Mode
COMMENT=		Matlab mode for Emacs

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		${BASEPKGNAME}

.include "../../editors/emacs/modules.mk"

.if ${EMACS_FLAVOR} == "emacs"
EMACS=	emacs
.else
EMACS=	xemacs
# matlab.el requires tempo, which lives in xemacs-packages rather
# than in XEmacs itself, so the byte-compile below cannot find it.
DEPENDS+=	xemacs-packages-[0-9]*:../../editors/xemacs-packages
.endif

SRCS=	matlab.el

do-build:
	for f in ${SRCS}; do						\
		${EMACS} --no-init-file --no-site-file -batch		\
		-f batch-byte-compile ${WRKSRC}/$$f;			\
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE:C|^${EMACS_PKGNAME_PREFIX}||}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE:C|^${EMACS_PKGNAME_PREFIX}||}

.include "../../mk/bsd.pkg.mk"
