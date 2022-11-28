# $NetBSD: Makefile,v 1.11 2022/11/28 19:26:41 jschauma Exp $
#

DISTNAME=	iana-etc-2.30
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://sethwklein.net/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christos@NetBSD.org
HOMEPAGE=	http://sethwklein.net/
COMMENT=	Tools to process the IANA source files into services and protocols
LICENSE=	osl

USE_TOOLS+=	gmake gawk

# does not install files, so don't bother bulk building it
NOT_FOR_BULK_PLATFORM=	*-*-*

.include "../../mk/bsd.pkg.mk"
