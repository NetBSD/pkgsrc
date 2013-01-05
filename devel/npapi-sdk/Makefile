# $NetBSD: Makefile,v 1.4 2013/01/05 11:44:07 obache Exp $
#

DISTNAME=	npapi-sdk-0.27.2
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/mgorny/npapi-sdk/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://bitbucket.org/mgorny/npapi-sdk/
COMMENT=	Reusable, released NPAPI-SDK
LICENSE=	mpl-1.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	npapi-sdk.pc.in

.include "../../mk/bsd.pkg.mk"
