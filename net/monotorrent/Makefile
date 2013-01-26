# $NetBSD: Makefile,v 1.11 2013/01/26 21:36:42 adam Exp $

DISTNAME=	monotorrent-0.72
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://projects.qnetp.net/attachments/download/13/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://monotorrent.com/
COMMENT=	Open source bittorrent library

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
USE_TOOLS+=	gmake bsdtar pkg-config
EXTRACT_USING=	bsdtar

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
