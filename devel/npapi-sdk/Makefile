# $NetBSD: Makefile,v 1.1.1.1 2011/12/17 14:11:07 obache Exp $
#

DISTNAME=	npapi-sdk-0.27
CATEGORIES=	devel
MASTER_SITES=	http://cloud.github.com/downloads/mgorny/npapi-sdk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/mgorny/npapi-sdk/
COMMENT=	Reusable, released NPAPI-SDK
LICENSE=	mpl-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	npapi-sdk.pc.in

.include "../../mk/bsd.pkg.mk"
