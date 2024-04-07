# $NetBSD: Makefile,v 1.1 2024/04/07 17:55:08 ryoon Exp $

DISTNAME=	manued-eeff13e4416aeedf6cd88b049bb7bba4b5b80ef7
PKGNAME=	manued-0.0.0.20191018
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=yamauchih/}
GITHUB_PROJECT=	manued
GITHUB_TAG=	eeff13e4416aeedf6cd88b049bb7bba4b5b80ef7

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/yamauchih/manued/
COMMENT=	Proofreading method implemented on Emacs
LICENSE=	gnu-gpl-v3

NO_BUILD=	yes

USE_LANGUAGES=	# none
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	${EMACS_LISPPREFIX} share/doc/manued

do-install:
	${INSTALL_DATA} ${WRKSRC}/manued.el \
		${DESTDIR}${EMACS_LISPPREFIX}
	cd ${WRKSRC} && \
	${FIND} doc memo samples tutorial Changelog README.* | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/share/doc/manued

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
