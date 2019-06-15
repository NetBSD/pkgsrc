# $NetBSD: Makefile,v 1.7 2019/06/15 15:18:22 christos Exp $
#

DISTNAME=	iana-etc-2.30
PKGREVISION=	1
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
