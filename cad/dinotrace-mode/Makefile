# $NetBSD: Makefile,v 1.19 2023/09/17 04:16:43 mef Exp $
#

VERSION=	9.4f
DISTNAME=	dinotrace-${VERSION}
PKGREVISION=	3
PKGNAME=	${EMACS_PKGNAME_PREFIX}dinotrace-mode-${VERSION}
CATEGORIES=	cad editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=veripool/}
GITHUB_PROJECT=	dinotrace
GITHUB_TAG=	v${VERSION}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	https://github.com/veripool/dinotrace/blob/master/README.rst
COMMENT=	Emacs major mode for dinotrace
LICENSE=	gnu-gpl-v3

DEPENDS+=	${EMACS_PKGNAME_PREFIX}verilog-mode>=3.13:../../cad/verilog-mode

# failed to build with emacs28; needs athena widgets which are not enabled by default
EMACS_VERSIONS_ACCEPTED=	emacs26 emacs28

.include "../../mk/bsd.prefs.mk"
.include "../../editors/emacs/modules.mk"

.if ${EMACS_FLAVOR} == "emacs"
EMACS=	emacs
.else
EMACS=	xemacs
.endif

SRCS=	dinotrace.el sim-log.el lucid.el

pre-build:
	${CP} ${PKGDIR}/files/lucid.el ${WRKSRC}/lisp/

do-build:
	for f in ${SRCS}; do						\
		${EMACS} --no-init-file --no-site-file -batch		\
	        --directory ${WRKSRC}/lisp/      \
		-f batch-byte-compile ${WRKSRC}/lisp/$$f;		\
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	cd ${WRKSRC}/lisp && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc}	\
		${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
