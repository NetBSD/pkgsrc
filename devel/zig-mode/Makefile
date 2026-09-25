# $NetBSD: Makefile,v 1.3 2026/09/25 09:48:07 wiz Exp $

DISTNAME=	zig-mode-0.0.20220105
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ziglang/}
GITHUB_PROJECT=	zig-mode
GITHUB_TAG=	aa20d630b8c413dab8d6bd120ec3ed5db5c9da70

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ziglang/zig-mode/
COMMENT=	Zig programming language mode for Emacs
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=		yes

EMACS_VERSIONS_INCOMPATIBLE=	xemacs214 xemacs215 xemacs214nox xemacs215nox

do-build:
	cd ${WRKSRC} && ${EMACS_BIN} -batch -f batch-byte-compile zig-mode.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/zig-mode
	${INSTALL_DATA} ${WRKSRC}/zig-mode.e* \
		${DESTDIR}${EMACS_LISPPREFIX}/zig-mode

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
