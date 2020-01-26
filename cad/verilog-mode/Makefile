# $NetBSD: Makefile,v 1.13 2020/01/26 17:30:48 rillig Exp $
#

DISTNAME=		verilog-mode-3.60
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		3
CATEGORIES=		cad editors
MASTER_SITES=		${MASTER_SITE_LOCAL}
# The latest can be fetched interactively from
# MASTER_SITES=		http://www.verilog.com/register.html

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		https://www.verilog.com/verilog-mode.html
COMMENT=		Verilog mode for Emacs

WRKSRC=			${WRKDIR}

.include "../../editors/emacs/modules.mk"

.if ${EMACS_FLAVOR} == "emacs"
EMACS=	emacs
.else
EMACS=	xemacs
.endif

SRCS=	verilog-mode.el

do-build:
	for f in ${SRCS}; do						\
		${EMACS} --no-init-file --no-site-file -batch		\
		-f batch-byte-compile ${WRKSRC}/$$f;			\
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc}	\
		${DESTDIR}${EMACS_LISPPREFIX}

.include "../../mk/bsd.pkg.mk"
