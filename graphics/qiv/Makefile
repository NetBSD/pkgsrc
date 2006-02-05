# $NetBSD: Makefile,v 1.19 2006/02/05 23:09:38 joerg Exp $

DISTNAME=	qiv-2.0-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.klografx.net/qiv/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://www.klografx.net/qiv/
COMMENT=	Quick image viewer

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
