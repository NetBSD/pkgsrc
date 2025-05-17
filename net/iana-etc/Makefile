# $NetBSD: Makefile,v 1.12 2025/05/17 19:09:43 zafer Exp $
#

DISTNAME=	iana-etc-2.30
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	https://sethwklein.net/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christos@NetBSD.org
HOMEPAGE=	https://sethwklein.net/
COMMENT=	Tools to process the IANA source files into services and protocols
LICENSE=	osl

USE_TOOLS+=	gmake gawk

# does not install files, so don't bother bulk building it
NOT_FOR_BULK_PLATFORM=	*-*-*

.include "../../mk/bsd.pkg.mk"
