# $NetBSD: Makefile,v 1.12 2014/01/01 11:52:28 wiz Exp $

DISTNAME=	flickcurl-1.25
PKGREVISION=	1
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
