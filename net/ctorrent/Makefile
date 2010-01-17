# $NetBSD: Makefile,v 1.9 2010/01/17 12:02:31 wiz Exp $

DISTNAME=	ctorrent-1.3.4
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctorrent/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctorrent.sourceforge.net/
COMMENT=	Bittorrent client for the console

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
