# $NetBSD: Makefile,v 1.4 2004/12/31 02:02:14 wiz Exp $

DISTNAME=	ctorrent-1.3.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctorrent/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ctorrent.sourceforge.net/
COMMENT=	Bittorrent client for the console

USE_LANGUAGES=		c c++
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
