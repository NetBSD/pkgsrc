# $NetBSD: Makefile,v 1.3 2002/08/20 12:11:11 wiz Exp $
#

DISTNAME=	qiv-1.8-src
PKGNAME=	qiv-1.8
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	graphics
MASTER_SITES=	http://www.klografx.net/qiv/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.klografx.net/qiv/
COMMENT=	Quick image viewer

USE_GMAKE=		yes
USE_BUILDLINK_ONLY=	yes

.include "../../graphics/imlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
