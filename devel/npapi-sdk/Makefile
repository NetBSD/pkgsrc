# $NetBSD: Makefile,v 1.2 2012/09/24 12:50:23 obache Exp $
#

DISTNAME=	npapi-sdk-0.27
CATEGORIES=	devel
MASTER_SITES=	http://cloud.github.com/downloads/mgorny/npapi-sdk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://bitbucket.org/mgorny/npapi-sdk/
COMMENT=	Reusable, released NPAPI-SDK
LICENSE=	mpl-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	npapi-sdk.pc.in

.include "../../mk/bsd.pkg.mk"
