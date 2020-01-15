# $NetBSD: Makefile,v 1.2 2020/01/15 16:24:18 nia Exp $

DISTNAME=	lr-1.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=leahneukirchen/}
GITHUB_PROJECT=	lr
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/leahneukirchen/lr
COMMENT=	List files, recursively
LICENSE=	mit

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
