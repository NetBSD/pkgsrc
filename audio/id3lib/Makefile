# $NetBSD: Makefile,v 1.9 2002/11/26 21:56:32 schmonz Exp $
#

DISTNAME=	id3lib-3.8.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3lib/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://id3lib.sourceforge.net/
COMMENT=	library for manipulating ID3v1 and ID3v2 tags

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
