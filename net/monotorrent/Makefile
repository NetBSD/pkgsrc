# $NetBSD: Makefile,v 1.8 2012/04/27 12:31:59 obache Exp $

DISTNAME=	monotorrent-0.72
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://projects.qnetp.net/attachments/download/13/

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
