# $NetBSD: Makefile,v 1.12 2004/01/24 15:46:44 grant Exp $
#

DISTNAME=	qiv-1.8-src
PKGNAME=	qiv-1.8
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.klografx.net/qiv/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.klografx.net/qiv/
COMMENT=	Quick image viewer

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_GNU_TOOLS+=	make
USE_BUILDLINK2=	yes

.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
