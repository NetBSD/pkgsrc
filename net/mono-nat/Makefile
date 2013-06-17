# $NetBSD: Makefile,v 1.9 2013/06/17 12:44:54 wiz Exp $

DISTNAME=	mono-nat-1.0.2
PKGREVISION=	7
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
