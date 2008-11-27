# $NetBSD: Makefile,v 1.1.1.1 2008/11/27 09:02:39 kefren Exp $

DISTNAME=	monotorrent-0.62
CATEGORIES=	net
MASTER_SITES=	http://monotorrent.com/Files/0.62/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://monotorrent.com/
COMMENT=	Open source bittorrent library

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
USE_TOOLS=	gmake gtar
EXTRACT_USING=	gtar

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
