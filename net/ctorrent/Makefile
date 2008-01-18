# $NetBSD: Makefile,v 1.7 2008/01/18 05:08:41 tnn Exp $

DISTNAME=	ctorrent-1.3.4
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctorrent/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctorrent.sourceforge.net/
COMMENT=	Bittorrent client for the console

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
