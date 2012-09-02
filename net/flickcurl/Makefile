# $NetBSD: Makefile,v 1.6 2012/09/02 15:12:51 wiz Exp $
#

DISTNAME=	flickcurl-1.23
CATEGORIES=	net
MASTER_SITES=	http://download.dajobe.org/flickcurl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.dajobe.org/flickcurl/
COMMENT=	Flickr API library
LICENSE=	gnu-lgpl-v2.1 OR gnu-gpl-v2 OR apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
