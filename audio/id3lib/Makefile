# $NetBSD: Makefile,v 1.8 2002/10/03 22:45:05 jlam Exp $
#

DISTNAME=	id3lib-3.8.0
PKGNAME=	id3lib-3.8.0.0.3
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
