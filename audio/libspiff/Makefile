# $NetBSD: Makefile,v 1.2 2007/11/08 18:58:48 bjs Exp $
#

DISTNAME=	libspiff-0.8.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libspiff/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://libspiff.sourceforge.net/
COMMENT=	XML Shareable Playlist Format (XSPF) library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

TEST_TARGET=	check

BUILDLINK_ABI_DEPENDS.expat+=	expat>=2.0.0nb1:../../textproc/expat

.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/uriparser/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
