# $NetBSD: Makefile,v 1.2 2015/05/19 13:33:04 mef Exp $

DISTNAME=	rainbow-delimiters-1.3.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jlr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.emacswiki.org/emacs/RainbowDelimiters
COMMENT=	Emacs mode for colorful parentheses highlighting

USE_LANGUAGES=	# none
MESSAGE_SUBST+=	LISPDIR=${EMACS_LISPPREFIX:Q}
INSTALLATION_DIRS=	${EMACS_LISPPREFIX}

do-build:
	cd ${WRKSRC} && ${EMACS_BIN} -batch -f batch-byte-compile rainbow-delimiters.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/rainbow-delimiters.* ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
