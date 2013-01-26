# $NetBSD: Makefile,v 1.7 2013/01/26 21:36:42 adam Exp $

DISTNAME=	mono-nat-1.0.2
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://projects.qnetp.net/attachments/download/22/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://projects.qnetp.net/projects/show/mono-nat
COMMENT=	C\# library for uPnP management

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
USE_TOOLS+=	gmake pkg-config

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
