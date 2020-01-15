# $NetBSD: Makefile,v 1.1 2020/01/15 14:56:46 nia Exp $

DISTNAME=	lr-1.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=leahneukirchen/}
GITHUB_PROJECT=	lr
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/leahneukirchen/lr
COMMENT=	List files, recursively
LICENSE=	mit

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
