# $NetBSD: Makefile,v 1.19 2004/03/23 05:39:23 jlam Exp $
#

DISTNAME=	id3lib-3.8.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3lib/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://id3lib.sourceforge.net/
COMMENT=	Library for manipulating ID3v1 and ID3v2 tags

USE_LANGUAGES=		c c++
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

CPPFLAGS+=-DID3_NEED_WCHAR_TEMPLATE

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
