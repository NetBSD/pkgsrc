# $NetBSD: Makefile,v 1.1 2020/12/12 13:32:51 nia Exp $

DISTNAME=	hexer-1.0.6
CATEGORIES=	editors
MASTER_SITES=	https://devel.ringlet.net/files/editors/hexer/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://devel.ringlet.net/editors/hexer/
COMMENT=	Vi-like binary editor
LICENSE=	hexer-license

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
