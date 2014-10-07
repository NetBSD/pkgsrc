# $NetBSD: Makefile,v 1.12 2014/10/07 16:47:13 adam Exp $

DISTNAME=	mono-nat-1.0.2
PKGREVISION=	10
CATEGORIES=	net
MASTER_SITES=	http://projects.qnetp.net/attachments/download/22/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://projects.qnetp.net/projects/show/mono-nat
COMMENT=	C\# library for uPnP management

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
USE_TOOLS+=	gmake pkg-config

.include "../../lang/mono2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
