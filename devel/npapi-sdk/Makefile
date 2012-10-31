# $NetBSD: Makefile,v 1.3 2012/10/31 11:17:32 asau Exp $
#

DISTNAME=	npapi-sdk-0.27
CATEGORIES=	devel
MASTER_SITES=	http://cloud.github.com/downloads/mgorny/npapi-sdk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://bitbucket.org/mgorny/npapi-sdk/
COMMENT=	Reusable, released NPAPI-SDK
LICENSE=	mpl-1.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	npapi-sdk.pc.in

.include "../../mk/bsd.pkg.mk"
