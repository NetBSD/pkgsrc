# $NetBSD: Makefile,v 1.6 2003/05/05 19:05:15 jmmv Exp $
#

DISTNAME=	qiv-1.8-src
PKGNAME=	qiv-1.8
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	graphics
MASTER_SITES=	http://www.klografx.net/qiv/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.klografx.net/qiv/
COMMENT=	Quick image viewer

USE_GMAKE=	yes
USE_BUILDLINK2=	yes

.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
