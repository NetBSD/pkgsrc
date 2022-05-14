# $NetBSD: Makefile,v 1.15 2022/05/14 22:25:32 dholland Exp $
#

VERSION=	9.4f
DISTNAME=	dinotrace-${VERSION}
PKGNAME=	${EMACS_PKGNAME_PREFIX}dinotrace-mode-${VERSION}
PKGREVISION=	1
CATEGORIES=	cad editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=veripool/}
GITHUB_PROJECT=	dinotrace
GITHUB_TAG=	v${VERSION}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.veripool.org/dinotrace/
COMMENT=	Emacs major mode for dinotrace
LICENSE=	gnu-gpl-v3

DEPENDS+=	${EMACS_PKGNAME_PREFIX}verilog-mode>=3.13:../../cad/verilog-mode

.include "../../mk/bsd.prefs.mk"
.include "../../editors/emacs/modules.mk"

.if ${EMACS_FLAVOR} == "emacs"
EMACS=	emacs
.else
EMACS=	xemacs
.endif

SRCS=	dinotrace.el sim-log.el

do-build:
	for f in ${SRCS}; do						\
		${EMACS} --no-init-file --no-site-file -batch		\
		-f batch-byte-compile ${WRKSRC}/lisp/$$f;		\
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	cd ${WRKSRC}/lisp && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc}	\
		${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
