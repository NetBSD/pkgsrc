# $NetBSD: Makefile,v 1.1 2016/11/16 10:39:31 leot Exp $

DISTNAME=	fzy-0.7
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
