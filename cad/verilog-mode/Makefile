# $NetBSD: Makefile,v 1.1.1.1 2002/10/14 02:28:18 dmcmahill Exp $
#

DISTNAME=		verilog-mode-3.60
CATEGORIES=		cad editors
MASTER_SITES=		${MASTER_SITE_LOCAL}
# The latest can be fetched interactively from
# MASTER_SITES=		http://www.verilog.com/register.html

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.verilog.com/verilog-mode.html
COMMENT=		Verilog mode for Emacs

WRKSRC=			${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.include "../../mk/emacs.mk"

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
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} ${EMACS_LISPPREFIX}

.include "../../mk/bsd.pkg.mk"
