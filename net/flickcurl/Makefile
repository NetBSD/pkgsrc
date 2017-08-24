# $NetBSD: Makefile,v 1.19 2017/08/24 20:03:35 adam Exp $

DISTNAME=	flickcurl-1.26
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://download.dajobe.org/flickcurl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.dajobe.org/flickcurl/
COMMENT=	Flickr API library
LICENSE=	gnu-lgpl-v2.1 OR gnu-gpl-v2 OR apache-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
