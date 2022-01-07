# $NetBSD: Makefile,v 1.7 2022/01/07 12:43:52 nros Exp $

DISTNAME=	libxspf-1.2.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libspiff/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libspiff.sourceforge.net/
COMMENT=	XML Shareable Playlist Format (XSPF) library
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=	xspf.pc.in

CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat:Q}
#CONFIGURE_ARGS+=	--with-uriparser=${BUILDLINK_PREFIX.uriparser:Q}

CONFIGURE_ARGS+=	--disable-test
#TEST_TARGET=		check

BUILDLINK_ABI_DEPENDS.expat+=		expat>=2.0.0nb1
BUILDLINK_API_DEPENDS.uriparser+=	uriparser>=0.7.5

.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/uriparser/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
