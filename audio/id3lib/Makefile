# $NetBSD: Makefile,v 1.21 2004/11/17 17:46:21 minskim Exp $
#

DISTNAME=	id3lib-3.8.3
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3lib/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://id3lib.sourceforge.net/
COMMENT=	Library for manipulating ID3v1 and ID3v2 tags

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

CPPFLAGS+=-DID3_NEED_WCHAR_TEMPLATE

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
