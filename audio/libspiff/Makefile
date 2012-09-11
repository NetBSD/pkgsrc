# $NetBSD: Makefile,v 1.7 2012/09/12 00:24:44 asau Exp $
#

DISTNAME=	libspiff-1.0.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libspiff/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libspiff.sourceforge.net/
COMMENT=	XML Shareable Playlist Format (XSPF) library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat:Q}
CONFIGURE_ARGS+=	--with-uriparser=${BUILDLINK_PREFIX.uriparser:Q}

TEST_TARGET=	check

BUILDLINK_ABI_DEPENDS.expat+=		expat>=2.0.0nb1
BUILDLINK_API_DEPENDS.uriparser+=	uriparser>=0.7.2

.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/uriparser/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
