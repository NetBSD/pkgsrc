# $NetBSD: Makefile,v 1.2 2002/05/20 15:19:43 wiz Exp $
#

DISTNAME=	qiv-1.7-src
PKGNAME=	qiv-1.7
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	graphics
MASTER_SITES=	http://www.klografx.net/qiv/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.klografx.net/qiv/download/
COMMENT=	Quick image viewer

USE_GMAKE=		yes
USE_BUILDLINK_ONLY=	yes

.include "../../graphics/imlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
