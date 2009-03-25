# $NetBSD: Makefile,v 1.3 2009/03/25 22:37:13 he Exp $

DISTNAME=	monotorrent-0.62
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://monotorrent.com/Files/0.62/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://monotorrent.com/
COMMENT=	Open source bittorrent library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
USE_TOOLS+=	gmake bsdtartar pkg-config
EXTRACT_USING=	bsdtar

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
