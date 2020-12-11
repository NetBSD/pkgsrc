# $NetBSD: Makefile,v 1.1 2020/12/11 13:38:57 nia Exp $

DISTNAME=	yank-1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=mptre/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mptre/yank
COMMENT=	Copy terminal output to clipboard
LICENSE=	mit

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
