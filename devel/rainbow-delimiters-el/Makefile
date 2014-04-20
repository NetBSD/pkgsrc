# $NetBSD: Makefile,v 1.1 2014/04/20 19:05:08 wiz Exp $

DISTNAME=	rainbow-delimiters
PKGNAME=	rainbow-delimiters-1.3.5
CATEGORIES=	devel
MASTER_SITES=	http://github.com/jlr/rainbow-delimiters/raw/master/
EXTRACT_SUFX=	.el

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.emacswiki.org/emacs/RainbowDelimiters
COMMENT=	Emacs mode for colorful parentheses highlighting

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
MESSAGE_SUBST+=	LISPDIR=${EMACS_LISPPREFIX:Q}
INSTALLATION_DIRS=	${EMACS_LISPPREFIX}

do-build:
	cd ${WRKSRC} && ${EMACS_BIN} -batch -f batch-byte-compile rainbow-delimiters.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/rainbow-delimiters.* ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
