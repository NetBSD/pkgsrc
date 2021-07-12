# $NetBSD: Makefile,v 1.2 2021/07/12 22:45:34 nia Exp $

DISTNAME=	hexer-1.0.6
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	https://devel.ringlet.net/files/editors/hexer/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://devel.ringlet.net/editors/hexer/
COMMENT=	Vi-like binary editor
LICENSE=	hexer-license

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
