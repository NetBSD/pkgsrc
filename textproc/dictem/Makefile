# $NetBSD: Makefile,v 1.1.1.1 2007/01/10 14:53:11 obache Exp $

DISTNAME=		dictem-0.81
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
#PKGREVISION=		1
CATEGORIES=		textproc editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dictem/} \
                        http://www.mova.org/~cheusov/pub/dictem/

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		http://freshmeat.net/projects/dictem/
COMMENT=		Dictionary client (RFC-2229) for [X]Emacs

DEPENDS+=		dict-client>=1.9.14:../../textproc/dict-client
#MESSAGE_SUBST+=		PREFIX=${PREFIX}

SRCS=			dictem.el
DOCS=			README NEWS COPYING ChangeLog

INSTALLATION_DIRS+=	share/doc/${PKGBASE} ${EMACS_LISPPREFIX:Q}

do-build:
.for f in ${SRCS}
	${EMACS_BIN:Q} --no-init-file --no-site-file -batch	\
		-f batch-byte-compile ${WRKSRC}/${f}
.endfor

do-install:
	set -e; \
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${EMACS_LISPPREFIX:Q};				\
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS}				\
			${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
