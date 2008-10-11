# $NetBSD: Makefile,v 1.11 2008/10/11 09:31:56 uebayasi Exp $
#

DISTNAME=		matlab.el
# we do this because we want DIST_SUBDIR to not change based on
# emacs vs xemacs
BASEPKGNAME=		matlab-mode-2.3.1
PKGNAME=		${EMACS_PKGNAME_PREFIX}${BASEPKGNAME}
PKGREVISION=		1
CATEGORIES=		editors math
MASTER_SITES=		http://www.mathworks.com/matlabcentral/files/104/
EXTRACT_SUFX=

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.mathworks.com/matlabcentral/fileexchange/loadFile.do?objectId=104&objectType=file
COMMENT=		Matlab mode for Emacs

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		${BASEPKGNAME}

.include "../../editors/emacs/modules.mk"

.if ${EMACS_FLAVOR} == "emacs"
EMACS=	emacs
.else
EMACS=	xemacs
.endif

SRCS=	matlab.el

do-build:
	for f in ${SRCS}; do						\
		${EMACS} --no-init-file --no-site-file -batch		\
		-f batch-byte-compile ${WRKSRC}/$$f;			\
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE:C|^xemacs-||}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
