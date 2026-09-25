# $NetBSD: Makefile,v 1.16 2026/09/25 09:48:05 wiz Exp $

DISTNAME=		verilog-mode-3.60
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		4
CATEGORIES=		cad editors
MASTER_SITES=		${MASTER_SITE_LOCAL}
# The latest can be fetched interactively from
# MASTER_SITES=		http://www.verilog.com/register.html

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.verilog.com/verilog-mode.html
COMMENT=		Verilog mode for Emacs

WRKSRC=			${WRKDIR}

EMACS_VERSIONS_INCOMPATIBLE=	xemacs214 xemacs215 xemacs214nox xemacs215nox

.include "../../editors/emacs/modules.mk"

SRCS=	verilog-mode.el

do-build:
	for f in ${SRCS}; do						\
		${EMACS_BIN} --no-init-file --no-site-file -batch		\
		-f batch-byte-compile ${WRKSRC}/$$f;			\
	done

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc}	\
		${DESTDIR}${EMACS_LISPPREFIX}

.include "../../mk/bsd.pkg.mk"
