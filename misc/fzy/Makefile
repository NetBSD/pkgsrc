# $NetBSD: Makefile,v 1.3 2017/04/17 09:51:54 leot Exp $

DISTNAME=	fzy-0.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jhawthorn/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/jhawthorn/fzy
COMMENT=	Fuzzy text selector for the terminal
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_ENV+=	MANDIR="${PREFIX}/${PKGMANDIR}"

USE_LANGUAGES=	c99

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
