# $NetBSD: Makefile,v 1.7 2022/07/25 11:12:23 wiz Exp $

DISTNAME=	npapi-sdk-0.27.2
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/mgorny/npapi-sdk/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/mgorny/npapi-sdk/
COMMENT=	Reusable, released NPAPI-SDK
LICENSE=	mpl-1.1

GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	npapi-sdk.pc.in

.include "../../mk/bsd.pkg.mk"
