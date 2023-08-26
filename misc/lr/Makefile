# $NetBSD: Makefile,v 1.4 2023/08/26 09:00:38 vins Exp $

DISTNAME=	lr-1.6
CATEGORIES=	misc
MASTER_SITES=	https://git.vuxu.org/lr/snapshot/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.vuxu.org/lr/about/
COMMENT=	List files, recursively
LICENSE=	mit

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
