# $NetBSD: Makefile,v 1.13 2017/01/19 18:52:27 agc Exp $

DISTNAME=		dictem-1.0.4
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dictem/}
MASTER_SITES+=		http://www.mova.org/~cheusov/pub/dictem/

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		http://freshmeat.net/projects/dictem/
COMMENT=		Dictionary client (RFC-2229) for [X]Emacs
LICENSE=		gnu-gpl-v2

DEPENDS+=		dict-client>=1.9.14:../../textproc/dict-client

SRCS=			dictem.el
DOCS=			README NEWS COPYING # ChangeLog

INSTALLATION_DIRS+=	share/doc/${PKGBASE} ${EMACS_LISPPREFIX}

do-build:
.for f in ${SRCS}
	${EMACS_BIN} --no-init-file --no-site-file -batch	\
		-f batch-byte-compile ${WRKSRC}/${f}
.endfor

do-install:
	set -e; \
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${DESTDIR}${EMACS_LISPPREFIX};		\
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS}				\
			${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
