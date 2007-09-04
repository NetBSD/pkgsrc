# $NetBSD: Makefile,v 1.27 2007/09/04 09:58:20 drochner Exp $
#

DISTNAME=	id3lib-3.8.3
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://id3lib.sourceforge.net/
COMMENT=	Library for manipulating ID3v1 and ID3v2 tags

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CPPFLAGS+=-DID3_NEED_WCHAR_TEMPLATE

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
