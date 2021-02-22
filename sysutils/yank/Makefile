# $NetBSD: Makefile,v 1.2 2021/02/22 20:36:28 wiz Exp $

DISTNAME=	yank-1.2.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=mptre/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mptre/yank
COMMENT=	Copy terminal output to clipboard
LICENSE=	mit

DEPENDS+=	xsel-[0-9]*:../../x11/xsel

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
