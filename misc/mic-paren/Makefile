# $NetBSD: Makefile,v 1.2 2022/05/14 22:25:40 dholland Exp $

DISTNAME=	mic-paren-3.13
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=emacsattic/}
GITHUB_TAG=	d0410c7d805c9aaf51a1bcefaaef092bed5824c4

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://melpa.org/\#/mic-paren
COMMENT=	Advanced highlighting of parenthesis
LICENSE=	gnu-gpl-v3

EMACS_MODULES=		base
EMACS_BUILDLINK=	yes

do-build:
	cd ${WRKSRC} && ${EMACS_BIN} -batch -f batch-byte-compile *.el

INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}
do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el  ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/*.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
