# $NetBSD: Makefile,v 1.1.1.1 2003/02/14 01:32:43 dmcmahill Exp $
#

DISTNAME=		matlab.el
PKGNAME=		matlab-mode-2.3
CATEGORIES=		editors math
MASTER_SITES=		http://www.mathworks.com/matlabcentral/files/104/
EXTRACT_SUFX=

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.mathworks.com/matlabcentral/fileexchange/loadFile.do?objectId=104&objectType=file
COMMENT=		Matlab mode for Emacs

WRKSRC=			${WRKDIR}

EXTRACT_CMD=		${CP} ${DOWNLOADED_DISTFILE} ${WRKDIR}
DIST_SUBDIR=		${PKGNAME}

.include "../../mk/emacs.mk"

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
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/${PKGBASE}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} ${EMACS_LISPPREFIX}/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
