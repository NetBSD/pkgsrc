# $NetBSD: Makefile,v 1.16 2004/11/26 22:18:27 snj Exp $

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
USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
