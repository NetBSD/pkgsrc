# $NetBSD: Makefile,v 1.11 2003/06/02 01:21:38 jschauma Exp $
#

DISTNAME=	id3lib-3.8.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3lib/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://id3lib.sourceforge.net/
COMMENT=	library for manipulating ID3v1 and ID3v2 tags

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
