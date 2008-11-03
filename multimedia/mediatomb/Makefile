# $NetBSD: Makefile,v 1.5 2008/11/03 17:04:51 tron Exp $

DISTNAME=	mediatomb-0.11.0
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mediatomb/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://mediatomb.cc/
COMMENT=	UPnP MediaServer with a web user interface

GNU_CONFIGURE=	yes

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

RCD_SCRIPTS=	mediatomb

.include "../../mk/bsd.prefs.mk"

PKG_GROUPS=			${MEDIATOMB_GROUP}
PKG_USERS=			${MEDIATOMB_USER}:${MEDIATOMB_GROUP}

PKG_GECOS.${MEDIATOMB_USER}=	MediaTomb Server
PKG_HOME.${MEDIATOMB_USER}=	${VARBASE}/mediatomb

FILES_SUBST+=			PKG_HOME=${PKG_HOME.${MEDIATOMB_USER}:Q}
FILES_SUBST+=			MEDIATOMB_GROUP=${MEDIATOMB_GROUP:Q}
FILES_SUBST+=			MEDIATOMB_USER=${MEDIATOMB_USER:Q}

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
