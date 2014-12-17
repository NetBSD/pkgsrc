# $NetBSD: Makefile,v 1.5 2014/12/17 11:16:32 obache Exp $
#

DISTNAME=	npapi-sdk-0.27.2
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/mgorny/npapi-sdk/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://bitbucket.org/mgorny/npapi-sdk/
COMMENT=	Reusable, released NPAPI-SDK
LICENSE=	mpl-1.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	npapi-sdk.pc.in

.include "../../mk/bsd.pkg.mk"
