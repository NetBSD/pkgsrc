# $NetBSD: Makefile,v 1.6 2015/03/05 20:29:13 tnn Exp $
#

DISTNAME=	iana-etc-2.30
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
