# $NetBSD: Makefile,v 1.4 2008/09/08 15:14:21 ahoka Exp $

DISTNAME=	mediatomb-0.11.0
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mediatomb/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://mediatomb.cc/
COMMENT=	UPnP MediaServer with a web user interface

GNU_CONFIGURE=	yes

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

PREFER.bind=	pkgsrc	# we need the package for the lwres lib

.include "options.mk"

.include "../../audio/taglib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../net/bind9/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
