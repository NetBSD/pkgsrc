# $NetBSD: Makefile,v 1.18 2005/05/22 20:08:07 jlam Exp $

DISTNAME=	qiv-2.0-src
PKGNAME=	${DISTNAME:S/-src//}
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
