# $NetBSD: Makefile,v 1.8 2016/04/20 12:10:25 nros Exp $

DISTNAME=		easyh10-1.5
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=easyh10/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://easyh10.sourceforge.net/
COMMENT=		Database tool for the iRiver H10 digital audio player
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-id3tag-library=${BUILDLINK_PREFIX.libid3tag}/lib
CONFIGURE_ARGS+=	--with-iconv-library=${BUILDLINK_PREFIX.iconv}/lib

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
